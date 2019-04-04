#include "lexer.h"

void Lexer::reserve(Word w) {
  words.insert(make_pair(w.lexeme, w));
}

Lexer::Lexer() {
  line = 1;
  peek = ' ';
  reserve(Word("if", Tag::IF));
  reserve(Word("else", Tag::ELSE));
  reserve(Word("while", Tag::WHILE));
  reserve(Word("do", Tag::DO));
  reserve(Word("break", Tag::BREAK));
  reserve(True);
  reserve(False);
  reserve(Int);
  reserve(Char);
  reserve(Bool);
  reserve(Float);
}

void Lexer::readch() {
  int i = cin.get();
  if (i != -1)
    peek = (char)i;
  else
    throw i; // EOF
}

bool Lexer::readch(char c) {
  readch();
  if (peek != c)
    return false;
  peek = ' ';
  return true;
}

Token Lexer::scan() {
  for ( ; ; readch()) {
    if (peek == ' ' || peek == '\t')
      continue;
    else if (peek == '\n')
      ++line;
    else
      break;
  }
  
  switch(peek) {
    case '&':
      if (readch('&'))
        return AND;
      else 
        return Token('&');
    case '|':
      if (readch('|'))
        return OR;
      else 
        return Token('|');
    case '=':
      if (readch('='))
        return eq;
      else
        return Token('=');
    case '!':
      if (readch('=')) 
        return ne;
      else 
        return Token('!');
    case '<':
      if (readch('=')) 
        return le;
      else 
        return Token('<');
    case '>':
      if (readch('=')) 
        return ge;
      else 
        return Token('>');
  }

  if (isdigit(peek)) {
    cout << "Token: " << left << setw(8);
    int v = 0;
    do {
      v = 10 * v + (peek - '0');
      readch();
    } while (isdigit(peek));

    cout << v;

    if (peek != '.')
      return Num(v);

    float x = v;
    float d = 10;
    for ( ; ; ) {
      readch();
      if (!isdigit(peek))
        break;
      x = x + (peek - '0')/d;
      d = d*10;
    }

    cout << x;

    return Real(x);
  }

  if (isalpha(peek)) {
    cout << "Token: " << left << setw(8);
    stringstream ss;
    do {
      ss << peek;
      readch();
    } while (isdigit(peek) || isalpha(peek));

    string s = ss.str();

    map<string, Word>::iterator it = words.find(s);
    if (it != words.end()) {
      cout << s;
      return it->second;
    }

    Word w(s, Tag::ID);
    words.insert(make_pair(s,w));
    cout << s;
    return w;    
  }

  Token tok(peek);
  peek = ' ';
  return tok;
}


