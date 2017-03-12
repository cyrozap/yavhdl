#ifndef VHDL_PARSE_TREE_H
#define VHDL_PARSE_TREE_H

#include <string>

enum ParseTreeNodeType
{
    // Various types of literals (spread throughout the spec)
    PT_LIT_NULL,
    PT_LIT_STRING,
    PT_LIT_BITSTRING,
    PT_LIT_DECIMAL,
    PT_LIT_BASED,
    PT_LIT_CHAR,
    PT_LIT_PHYS,

    // Names and identifiers, section 8
    PT_BASIC_ID,
    PT_EXT_ID,

    PT_NAME_SELECTED,
    PT_NAME_AMBIG_PARENS,
    PT_NAME_SLICE,
    PT_NAME_ATTRIBUTE,
    PT_NAME_EXT_CONST,
    PT_NAME_EXT_SIG,
    PT_NAME_EXT_VAR,

    PT_PACKAGE_PATHNAME,
    PT_ABSOLUTE_PATHNAME,
    PT_RELATIVE_PATHNAME,
    PT_PARTIAL_PATHNAME,
    PT_PATHNAME_ELEMENT,
    PT_PATHNAME_ELEMENT_GENERATE_LABEL,

    PT_SIGNATURE,

    PT_SUBTYPE_INDICATION,
    PT_RECORD_ELEMENT_RESOLUTION,

    PT_RANGE,

    PT_ARRAY_CONSTRAINT,
    PT_INDEX_CONSTRAINT,
    PT_RECORD_CONSTRAINT,
    PT_RECORD_ELEMENT_CONSTRAINT,

    PT_EXPRESSION_LIST,
    PT_ID_LIST,
    PT_RECORD_RESOLUTION,

    PT_TOK_ALL,
    PT_TOK_OPEN,

    // Expressions, section 9
    PT_UNARY_OPERATOR,
    PT_BINARY_OPERATOR,

    PT_AGGREGATE,
    PT_ELEMENT_ASSOCIATION,
    PT_CHOICES,
    PT_CHOICES_OTHER,
    PT_QUALIFIED_EXPRESSION,
    PT_ALLOCATOR,

    PT_FUNCTION_CALL,
    PT_PARAMETER_ASSOCIATION_LIST,
    PT_PARAMETER_ASSOCIATION_ELEMENT,
    PT_FORMAL_PART_FN,

    // Sequential statements, section 10
    PT_STATEMENT_LABEL,
    PT_RETURN_STATEMENT,
    PT_NULL_STATEMENT,
    PT_ASSERTION_STATEMENT,
    PT_REPORT_STATEMENT,
    PT_NEXT_STATEMENT,
    PT_EXIT_STATEMENT,
    PT_SEQUENCE_OF_STATEMENTS,
    PT_IF_STATEMENT,
    PT_ELSIF,
    PT_ELSIF_LIST,
};

// Operators, section 9.2
enum ParseTreeOperatorType
{
    OP_COND,
    OP_AND,
    OP_OR,
    OP_NAND,
    OP_NOR,
    OP_XOR,
    OP_XNOR,
    OP_EQ,
    OP_NEQ,
    OP_LT,
    OP_LTE,
    OP_GT,
    OP_GTE,
    OP_MEQ,
    OP_MNE,
    OP_MLT,
    OP_MLE,
    OP_MGT,
    OP_MGE,
    OP_SLL,
    OP_SRL,
    OP_SLA,
    OP_SRA,
    OP_ROL,
    OP_ROR,
    OP_ADD,
    OP_SUB,
    OP_CONCAT,
    OP_MUL,
    OP_DIV,
    OP_MOD,
    OP_REM,
    OP_EXP,
    OP_ABS,
    OP_NOT,
};

enum ParseTreeRangeDirection
{
    RANGE_DOWN,
    RANGE_UP,
};

// Definition of a parse tree node
#define NUM_FIXED_PIECES 8

struct VhdlParseTreeNode {
    enum ParseTreeNodeType type;

    // Contents
    std::string *str;
    std::string *str2;
    char chr;
    int integer;
    struct VhdlParseTreeNode *pieces[NUM_FIXED_PIECES];
    int piece_count;

    ParseTreeOperatorType op_type;
    ParseTreeRangeDirection range_dir;

    VhdlParseTreeNode(enum ParseTreeNodeType type);
    ~VhdlParseTreeNode();

    void debug_print();
};

#endif
