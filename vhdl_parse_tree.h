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
    PT_CASE_STATEMENT,
    PT_CASE_STATEMENT_ALTERNATIVE,
    PT_CASE_STATEMENT_ALTERNATIVE_LIST,
    PT_LOOP_STATEMENT,
    PT_ITERATION_WHILE,
    PT_ITERATION_FOR,
    PT_PARAMETER_SPECIFICATION,
    PT_WAIT_STATEMENT,

    PT_NAME_LIST,

    PT_SIMPLE_WAVEFORM_ASSIGNMENT,
    PT_WAVEFORM,
    PT_WAVEFORM_UNAFFECTED,
    PT_WAVEFORM_ELEMENT,
    PT_DELAY_TRANSPORT,
    PT_DELAY_INERTIAL,
    PT_SIMPLE_FORCE_ASSIGNMENT,
    PT_SIMPLE_RELEASE_ASSIGNMENT,
    PT_CONDITIONAL_WAVEFORM_ASSIGNMENT,
    PT_CONDITIONAL_WAVEFORMS,
    PT_CONDITIONAL_WAVEFORM_ELSE,
    PT_CONDITIONAL_WAVEFORM_ELSE_LIST,
    PT_CONDITIONAL_FORCE_ASSIGNMENT,
    PT_CONDITIONAL_EXPRESSIONS,
    PT_CONDITIONAL_EXPRESSION_ELSE,
    PT_CONDITIONAL_EXPRESSION_ELSE_LIST,
    PT_SELECTED_WAVEFORM_ASSIGNMENT,
    PT_SELECTED_WAVEFORMS,
    PT_SELECTED_WAVEFORM,
    PT_SELECTED_FORCE_ASSIGNMENT,
    PT_SELECTED_EXPRESSIONS,
    PT_SELECTED_EXPRESSION,
    PT_SIMPLE_VARIABLE_ASSIGNMENT,
    PT_CONDITIONAL_VARIABLE_ASSIGNMENT,
    PT_SELECTED_VARIABLE_ASSIGNMENT,

    PT_FULL_TYPE_DECLARATION,
    PT_ENUMERATION_TYPE_DEFINITION,
    PT_ENUM_LITERAL_LIST,
    PT_INTEGER_FLOAT_TYPE_DEFINITION,
    PT_PHYSICAL_TYPE_DEFINITION,
    PT_SECONDARY_UNIT_DECLARATION,
    PT_SECONDARY_UNIT_DECLARATION_LIST,
    PT_CONSTRAINED_ARRAY_DEFINITION,
    PT_INDEX_SUBTYPE_DEFINITION_LIST,
    PT_UNBOUNDED_ARRAY_DEFINITION,
    PT_RECORD_TYPE_DEFINITION,
    PT_ELEMENT_DECLARATION,
    PT_ELEMENT_DECLARATION_LIST,
    // Real identifiers, not identifiers or selected names
    // FIXME
    PT_ID_LIST_REAL,
    PT_ACCESS_TYPE_DEFINITION,
    PT_INCOMPLETE_TYPE_DECLARATION,
    PT_FILE_TYPE_DEFINITION,

    PT_PROCESS,
    PT_DECLARATION_LIST,

    PT_SUBTYPE_DECLARATION,
    PT_CONSTANT_DECLARATION,
    PT_VARIABLE_DECLARATION,
    PT_FILE_DECLARATION,
    PT_ALIAS_DECLARATION,
    PT_FILE_OPEN_INFORMATION,
    PT_ATTRIBUTE_DECLARATION,
    PT_SUBPROGRAM_DECLARATION,
    PT_PROCEDURE_SPECIFICATION,
    PT_FUNCTION_SPECIFICATION,
    PT_SUBPROGRAM_HEADER,
    PT_INTERFACE_LIST,
    PT_INTERFACE_FILE_DECLARATION,
    PT_INTERFACE_AMBIG_OBJ_DECLARATION,
    PT_INTERFACE_CONSTANT_DECLARATION,
    PT_INTERFACE_SIGNAL_DECLARATION,
    PT_INTERFACE_VARIABLE_DECLARATION,
    PT_INTERFACE_MODE,
    PT_INTERFACE_TYPE_DECLARATION,
    PT_INTERFACE_SUBPROGRAM_DECLARATION,
    PT_INTERFACE_PROCEDURE_SPECIFICATION,
    PT_INTERFACE_FUNCTION_SPECIFICATION,
    PT_INTERFACE_SUBPROGRAM_DEFAULT_BOX,

    PT_GENERIC_MAP_ASPECT,
    PT_PORT_MAP_ASPECT,
    PT_ASSOCIATION_LIST,
    PT_ASSOCIATION_ELEMENT,
    PT_INERTIAL_EXPRESSION,

    PT_SUBPROGRAM_INSTANTIATION_DECLARATION,

    PT_SUBPROGRAM_BODY,
    PT_SUBTYPE_INDICATION_AMBIG_WTF,

    PT_ELEMENT_RESOLUTION_NEST,

    PT_USE_CLAUSE,
    PT_SELECTED_NAME_LIST,

    PT_ATTRIBUTE_SPECIFICATION,
    PT_ENTITY_SPECIFICATION,
    PT_ENTITY_CLASS,
    PT_ENTITY_NAME_LIST,
    PT_ENTITY_NAME_LIST_OTHERS,
    PT_ENTITY_NAME_LIST_ALL,
    PT_ENTITY_DESIGNATOR,

    PT_GROUP_TEMPLATE_DECLARATION,
    PT_ENTITY_CLASS_ENTRY_LIST,
    PT_ENTITY_CLASS_ENTRY,

    PT_GROUP_DECLARATION,

    PT_PACKAGE_DECLARATION,
    PT_PACKAGE_HEADER,

    PT_SIGNAL_DECLARATION,
    PT_SIGNAL_KIND,

    PT_PACKAGE_BODY,

    PT_PACKAGE_INSTANTIATION_DECLARATION,

    PT_INTERFACE_PACKAGE_DECLARATION,
    PT_INTERFACE_PACKAGE_GENERIC_MAP_BOX,
    PT_INTERFACE_PACKAGE_GENERIC_MAP_DEFAULT,

    PT_PROTECTED_TYPE_DECLARATION,
    PT_PROTECTED_TYPE_BODY,

    PT_COMPONENT_DECLARATION,

    PT_DISCONNECTION_SPECIFICATION,
    PT_GUARDED_SIGNAL_SPECIFICATION,
    PT_SIGNAL_LIST_OTHERS,
    PT_SIGNAL_LIST_ALL,

    PT_CONCURRENT_PROCEDURE_CALL,
    PT_CONCURRENT_ASSERTION_STATEMENT,

    PT_COMPONENT_INSTANTIATION,
    PT_INSTANTIATED_UNIT_COMPONENT,
    PT_INSTANTIATED_UNIT_ENTITY,
    PT_INSTANTIATED_UNIT_CONFIGURATION,

    PT_CONCURRENT_SIMPLE_SIGNAL_ASSIGNMENT,
    PT_CONCURRENT_CONDITIONAL_SIGNAL_ASSIGNMENT,
    PT_CONCURRENT_SELECTED_SIGNAL_ASSIGNMENT,

    PT_SEQUENCE_OF_CONCURRENT_STATEMENTS,

    PT_BLOCK,
    PT_BLOCK_HEADER,

    PT_FOR_GENERATE,
    PT_IF_GENERATE,
    PT_CASE_GENERATE,
    PT_GENERATE_BODY,
    PT_IF_GENERATE_ELSIF,
    PT_IF_GENERATE_ELSIF_LIST,
    PT_CASE_GENERATE_ALTERNATIVE,
    PT_CASE_GENERATE_ALTERNATIVE_LIST,

    PT_SIMPLE_CONFIGURATION_SPECIFICATION,
    PT_INSTANTIATION_LIST_OTHERS,
    PT_INSTANTIATION_LIST_ALL,
    PT_COMPONENT_SPECIFICATION,
    PT_BINDING_INDICATION,
    PT_ENTITY_ASPECT_ENTITY,
    PT_ENTITY_ASPECT_CONFIGURATION,
    PT_ENTITY_ASPECT_OPEN,
    PT_VERIFICATION_UNIT_BINDING_INDICATION,
    PT_VERIFICATION_UNIT_BINDING_INDICATION_LIST,
    PT_COMPOUND_CONFIGURATION_SPECIFICATION,

    PT_ENTITY,
    PT_ENTITY_HEADER,
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

enum ParseTreeForceMode
{
    FORCE_UNSPEC,
    FORCE_IN,
    FORCE_OUT,
};

enum ParseTreeFunctionPurity
{
    PURITY_UNSPEC,
    PURITY_PURE,
    PURITY_IMPURE,
};

enum ParseTreeInterfaceObjectMode
{
    MODE_UNSPEC,
    MODE_IN,
    MODE_OUT,
    MODE_INOUT,
    MODE_BUFFER,
    MODE_LINKAGE,
};

enum ParseTreeSubprogramKind
{
    SUBPROGRAM_UNSPEC,
    SUBPROGRAM_PROCEDURE,
    SUBPROGRAM_FUNCTION,
};

enum ParseTreeEntityClass
{
    ENTITY_ENTITY,
    ENTITY_ARCHITECTURE,
    ENTITY_CONFIGURATION,
    ENTITY_PROCEDURE,
    ENTITY_FUNCTION,
    ENTITY_PACKAGE,
    ENTITY_TYPE,
    ENTITY_SUBTYPE,
    ENTITY_CONSTANT,
    ENTITY_SIGNAL,
    ENTITY_VARIABLE,
    ENTITY_COMPONENT,
    ENTITY_LABEL,
    ENTITY_LITERAL,
    ENTITY_UNITS,
    ENTITY_GROUP,
    ENTITY_FILE,
    ENTITY_PROPERTY,
    ENTITY_SEQUENCE,
};

enum ParseTreeSignalKind
{
    SIGKIND_UNSPEC,
    SIGKIND_REGISTER,
    SIGKIND_BUS,
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
    bool boolean;
    bool boolean2;
    bool boolean3;
    struct VhdlParseTreeNode *pieces[NUM_FIXED_PIECES];
    int piece_count;

    ParseTreeOperatorType op_type;
    ParseTreeRangeDirection range_dir;
    ParseTreeForceMode force_mode;
    ParseTreeFunctionPurity purity;
    ParseTreeInterfaceObjectMode interface_mode;
    ParseTreeSubprogramKind subprogram_kind;
    ParseTreeEntityClass entity_class;
    ParseTreeSignalKind signal_kind;

    VhdlParseTreeNode(enum ParseTreeNodeType type);
    ~VhdlParseTreeNode();

    void debug_print();
};

#endif
