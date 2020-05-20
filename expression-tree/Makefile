#############################################################################
#
#  makefile for tree traversal
#
#############################################################################
#
#  If you move this makefile, update the variable below
#  or else depend won't work.
#
#############################################################################

MAKEFILE	= Makefile
CC		= g++
CFILES		= Composite_Add_Node.cpp Composite_Binary_Node.cpp Composite_Unary_Node.cpp Composite_Divide_Node.cpp Evaluation_Visitor.cpp getopt.cpp Interpreter.cpp Leaf_Node.cpp LQueue.cpp main.cpp Composite_Multiply_Node.cpp Composite_Negate_Node.cpp Component_Node.cpp Options.cpp Refcounter.cpp LStack.cpp Composite_Subtract_Node.cpp Expression_Tree_Iterator.cpp Expression_Tree_Iterator_Impl.cpp Print_Visitor.cpp Expression_Tree_Context.cpp Expression_Tree_Command.cpp Expression_Tree_Command_Factory.cpp Expression_Tree_Command_Factory_Impl.cpp Expression_Tree_State.cpp Reactor.cpp Event_Handler.cpp Expression_Tree_Event_Handler.cpp Expression_Tree_Command_Impl.cpp Visitor.cpp
HFILES		= Composite_Add_Node.h Composite_Binary_Node.h Composite_Unary_Node.h Composite_Divide_Node.h Evaluation_Visitor.h getopt.h Interpreter.h Leaf_Node.h Expression_Tree_Level_Order_Iterator_Impl.h LQueue.h Composite_Multiply_Node.h Composite_Negate_Node.h Component_Node.h Options.h Refcounter.h LStack.h Composite_Subtract_Node.h Expression_Tree_Iterator.h Expression_Tree_Iterator_Impl.h Typedefs.h Visitor.h Expression_Tree_Context.h Expression_Tree_Command.h Expression_Tree_Command_Factory.h Expression_Tree_Command_Factory_Impl.h Expression_Tree_State.h Reactor.h Event_Handler.h Expression_Tree_Event_Handler.h Print_Visitor.h Expression_Tree_Command_Impl.h Visitor.h
OFILES		= main.o Interpreter.o Expression_Tree.o Expression_Tree_Iterator.o Evaluation_Visitor.o Print_Visitor.o Leaf_Node.o Composite_Subtract_Node.o Composite_Multiply_Node.o Expression_Tree_Iterator_Impl.o Composite_Add_Node.o Composite_Negate_Node.o Options.o Composite_Divide_Node.o Component_Node.o Composite_Binary_Node.o Composite_Unary_Node.o getopt.o Expression_Tree_Context.o Expression_Tree_Command.o Expression_Tree_Command_Factory.o Expression_Tree_Command_Factory_Impl.o Expression_Tree_State.o Reactor.o Event_Handler.o Expression_Tree_Event_Handler.o Expression_Tree_Command_Impl.o Visitor.o
#############################################################################
# Flags for Installation
#############################################################################
BINDIR		= .
#############################################################################

DFLAGS		= -ggdb -std=c++0x -Wno-deprecated
IFLAGS          = 
OPTFLAGS	=  # Enable this flag if compiler supports templates...
LDFLAGS		= -g
CFLAGS		= $(IFLAGS) $(OPTFLAGS) $(DFLAGS)

#############################################################################
# G++ directives
#############################################################################
.SUFFIXES: .C .cpp
.cpp.o:
	$(CC) $(CFLAGS) -c $<
#############################################################################

all: tree-traversal

tree-traversal: $(OFILES)
	$(CC) $(LDFLAGS) $(OFILES) -o $@

clean:
	/bin/rm -f *.o *.out *~ core

realclean: clean
	/bin/rm -rf tree-traversal

depend:
	g++dep -f $(MAKEFILE) $(CFILES)

# DO NOT DELETE THIS LINE -- g++dep uses it.
# DO NOT PUT ANYTHING AFTER THIS LINE, IT WILL GO AWAY.

Composite_Add_Node.o: Composite_Add_Node.cpp Component_Node.h Visitor.h \
  Composite_Add_Node.h Composite_Binary_Node.h Composite_Unary_Node.h
Composite_Binary_Node.o: Composite_Binary_Node.cpp \
  Composite_Binary_Node.h Composite_Unary_Node.h Component_Node.h
Composite_Unary_Node.o: Composite_Unary_Node.cpp Composite_Unary_Node.h \
  Component_Node.h
Composite_Divide_Node.o: Composite_Divide_Node.cpp \
  Composite_Binary_Node.h Composite_Unary_Node.h Component_Node.h \
  Composite_Divide_Node.h Visitor.h
Evaluation_Visitor.o: Evaluation_Visitor.cpp Leaf_Node.h Component_Node.h \
  Composite_Negate_Node.h Composite_Unary_Node.h Composite_Add_Node.h \
  Composite_Binary_Node.h Composite_Subtract_Node.h \
  Composite_Divide_Node.h Composite_Multiply_Node.h Evaluation_Visitor.h \
  Visitor.h LStack.h LStack.cpp
getopt.o: getopt.cpp
Interpreter.o: Interpreter.cpp Component_Node.h Leaf_Node.h \
  Composite_Negate_Node.h Composite_Unary_Node.h Composite_Add_Node.h \
  Composite_Binary_Node.h Composite_Subtract_Node.h \
  Composite_Divide_Node.h Composite_Multiply_Node.h Interpreter.h \
  Expression_Tree.h Refcounter.h Refcounter.cpp
Leaf_Node.o: Leaf_Node.cpp Component_Node.h Visitor.h Leaf_Node.h
LQueue.o: LQueue.cpp LQueue.h LQueue.cpp
main.o: main.cpp Options.h Reactor.h Expression_Tree_Event_Handler.h \
  Event_Handler.h Expression_Tree_Context.h Expression_Tree.h \
  Refcounter.h Refcounter.cpp Expression_Tree_State.h \
  Expression_Tree_Command_Factory.h Expression_Tree_Command.h
Composite_Multiply_Node.o: Composite_Multiply_Node.cpp Component_Node.h \
  Composite_Binary_Node.h Composite_Unary_Node.h \
  Composite_Multiply_Node.h Visitor.h
Composite_Negate_Node.o: Composite_Negate_Node.cpp Component_Node.h \
  Composite_Unary_Node.h Visitor.h Composite_Negate_Node.h
Component_Node.o: Component_Node.cpp Component_Node.h Visitor.h
Options.o: Options.cpp getopt.h Options.h LQueue.h LQueue.cpp LStack.h \
  LStack.cpp Typedefs.h Component_Node.h Expression_Tree.h Refcounter.h \
  Refcounter.cpp
Refcounter.o: Refcounter.cpp Refcounter.h Refcounter.cpp
LStack.o: LStack.cpp LStack.h LStack.cpp
Composite_Subtract_Node.o: Composite_Subtract_Node.cpp Component_Node.h \
  Visitor.h Composite_Binary_Node.h Composite_Unary_Node.h \
  Composite_Subtract_Node.h
Expression_Tree_Iterator.o: Expression_Tree_Iterator.cpp Component_Node.h \
  Refcounter.h Refcounter.cpp Expression_Tree_Iterator.h \
  Expression_Tree_Iterator_Impl.h LStack.h LStack.cpp LQueue.h LQueue.cpp
Expression_Tree_Iterator_Impl.o: Expression_Tree_Iterator_Impl.cpp \
  Expression_Tree.h Refcounter.h Refcounter.cpp \
  Expression_Tree_Iterator_Impl.h LStack.h LStack.cpp LQueue.h LQueue.cpp \
  Component_Node.h
Visitor.o: Visitor.h
Print_Visitor.o: Print_Visitor.cpp Visitor.cpp Leaf_Node.h Component_Node.h \
  Composite_Negate_Node.h Composite_Unary_Node.h Composite_Add_Node.h \
  Composite_Binary_Node.h Composite_Subtract_Node.h \
  Composite_Divide_Node.h Composite_Multiply_Node.h Print_Visitor.h \
  Visitor.h
Expression_Tree_Context.o: Expression_Tree_Context.cpp \
  Expression_Tree_Context.h Expression_Tree.h Refcounter.h Refcounter.cpp \
  Expression_Tree_State.h
Expression_Tree_Command.o: Expression_Tree_Command.cpp \
  Expression_Tree_Command.h Refcounter.h Refcounter.cpp \
  Expression_Tree_Command_Impl.h
Expression_Tree_Command_Factory.o: Expression_Tree_Command_Factory.cpp \
  Expression_Tree_Command_Factory.h Expression_Tree_Command.h \
  Refcounter.h Refcounter.cpp Expression_Tree_Command_Factory_Impl.h \
  Expression_Tree_Context.h Expression_Tree.h Expression_Tree_State.h
Expression_Tree_Command_Factory_Impl.o:  \
 Expression_Tree_Command_Factory_Impl.cpp \
  Expression_Tree_Command_Factory_Impl.h Expression_Tree_Command.h \
  Refcounter.h Refcounter.cpp Expression_Tree_Context.h Expression_Tree.h \
  Expression_Tree_State.h Expression_Tree_Command_Impl.h
Expression_Tree_State.o: Expression_Tree_State.cpp \
  Expression_Tree_Context.h Expression_Tree.h Refcounter.h Refcounter.cpp \
  Expression_Tree_State.h Expression_Tree_Iterator.h \
  Expression_Tree_Iterator_Impl.h LStack.h LStack.cpp LQueue.h LQueue.cpp \
  Component_Node.h Interpreter.h Print_Visitor.h Visitor.h \
  Evaluation_Visitor.h
Reactor.o: Reactor.cpp Reactor.h Event_Handler.h
Event_Handler.o: Event_Handler.cpp Event_Handler.h
Expression_Tree_Event_Handler.o: Expression_Tree_Event_Handler.cpp \
  Expression_Tree_Event_Handler.h Event_Handler.h \
  Expression_Tree_Context.h Expression_Tree.h Refcounter.h Refcounter.cpp \
  Expression_Tree_State.h Expression_Tree_Command_Factory.h \
  Expression_Tree_Command.h Reactor.h Expression_Tree_Command_Impl.h
Expression_Tree_Command_Impl.o: Expression_Tree_Command_Impl.cpp \
  Expression_Tree_Context.h Expression_Tree.h Refcounter.h Refcounter.cpp \
  Expression_Tree_State.h Expression_Tree_Command_Factory_Impl.h \
  Expression_Tree_Command.h Expression_Tree_Command_Impl.h

# IF YOU PUT ANYTHING HERE IT WILL GO AWAY
