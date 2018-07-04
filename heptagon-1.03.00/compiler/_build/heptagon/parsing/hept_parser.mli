
(* The type of tokens. *)

type token = 
  | WITH
  | WHENOT
  | WHEN
  | VAR
  | VAL
  | UNTIL
  | UNSAFE
  | UNLESS
  | TYPE
  | THREE_DOTS
  | THEN
  | TEL
  | SWITCH
  | SUBTRACTIVE of (string)
  | STRING of (string)
  | STATE
  | STAR
  | SPLIT
  | SEMICOL
  | RPAREN_GREATER
  | RPAREN
  | RETURNS
  | RESET
  | REINIT
  | REACHABLE
  | RBRACKET
  | RBRACE
  | PRESENT
  | PREFIX of (string)
  | PRE
  | PRAGMA of (string * string)
  | POWER
  | OR
  | OPEN
  | ONOT
  | ON
  | NOT
  | NODE
  | MERGE
  | MAPI
  | MAPFOLD
  | MAP
  | LPAREN
  | LET
  | LESS_LPAREN
  | LESS_GREATER
  | LESSRBRACKET
  | LBRACKETGREATER
  | LBRACKET
  | LBRACE
  | LAST
  | INT of (int)
  | INLINED
  | INIT
  | INFIX4 of (string)
  | INFIX3 of (string)
  | INFIX2 of (string)
  | INFIX1 of (string)
  | INFIX0 of (string)
  | IN
  | IF
  | IDENT of (string)
  | FUN
  | FOLDI
  | FOLD
  | FLOAT of (float)
  | FBY
  | EXTERNAL
  | EVERY
  | EQUALEQUAL
  | EQUAL
  | EOF
  | ENFORCE
  | END
  | ELSE
  | DOUBLE_LESS
  | DOUBLE_GREATER
  | DOUBLE_DOT
  | DOT
  | DONE
  | DO
  | DEFAULT
  | Constructor of (string)
  | CONTRACT
  | CONTINUE
  | CONST
  | COMMA
  | COLONCOLON
  | COLON
  | BOOL of (bool)
  | BARBAR
  | BAR
  | AUTOMATON
  | ATTRACTIVE
  | AT
  | ASSUME
  | ARROW
  | AROBASE
  | AMPERSAND
  | AMPERAMPER

(* This exception is raised by the monolithic API functions. *)

exception Error

(* The monolithic API. *)

val program: (Lexing.lexbuf -> token) -> Lexing.lexbuf -> (Hept_parsetree.program)

val interface: (Lexing.lexbuf -> token) -> Lexing.lexbuf -> (Hept_parsetree.interface)

module MenhirInterpreter : sig
  
  (* The incremental API. *)
  
  include MenhirLib.IncrementalEngine.INCREMENTAL_ENGINE
    with type token = token
  
end

(* The entry point(s) to the incremental API. *)

module Incremental : sig
  
  val program: Lexing.position -> (Hept_parsetree.program) MenhirInterpreter.checkpoint
  
  val interface: Lexing.position -> (Hept_parsetree.interface) MenhirInterpreter.checkpoint
  
end
