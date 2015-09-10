# ijava
Final Compiler Project from a subset of the Java language called imperative Java - Compilers Subject UC

Description
----------------
This project consists in the development of a compiler for the language iJava (imperative Java), that is a small subset of the Programming Language Java (v 5.0). Every iJava program consists of only one class with the respective method (main). However this class may have other methods or attributes, every single one of them are static and public as well.

This Project consists primarily on 3 phases. First we have created the Lexical Analysis using C and Lex; in the second phase, it has consisted on the creation of the Syntatic Analysis using yacc/bison to construct the Abstract Syntax Tree and consequently the Semantic Analysis with the construction of the Symbols Table and detection of Semantic Errors; in the third and final phase, we have generated the code in LLVM, resulting from this whole process.


Screenshots
----------------

- Phase 1 (Lexical Analyzer)
  - <img src="https://github.com/cyberaa/ijava/blob/master/Screenshots/lexer.png" width="500px">
 
-------------
 - Phase 2
    - Abstract Syntax Tree
       - <img src="https://github.com/cyberaa/ijava/blob/master/Screenshots/yacc%20-%20AST.png" width="500px">
 
    - Syntax Error Detection 
       - <img src="https://github.com/cyberaa/ijava/blob/master/Screenshots/Syntax%20Errors.png" width="500px">
    
    - Symbolic Table
       - <img src="https://github.com/cyberaa/ijava/blob/master/Screenshots/symbolic%20table.png" width="500px">
    
    - Semantic Error Detection
       - <img src="https://github.com/cyberaa/ijava/blob/master/Screenshots/Semantic%20Error.png" width="500px">

--------------
  - Phase 3 (Code Generation)
      - LLVM
          - <img src="https://github.com/cyberaa/ijava/blob/master/Screenshots/generation%20of%20LLVM%20code.png" width="500px">
