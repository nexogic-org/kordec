#ifndef CODE_LEXER_H
#define CODE_LEXER_H

/**
 * Kordec Token定义
 * 按功能模块分类，便于维护和查阅
 */
typedef enum {
    // 基础特殊Token (非语法元素，用于标识状态)
    K_EOF,         // 文件结束特殊Token
    K_ERROR,       // 词法错误标记
    K_NIL,         // nil 空值

    // 基础分隔符 (单字符语法分隔/界定符号)
    K_SEMICOLON,   // ; 分号
    K_LBRACE,      // { 左大括号
    K_RBRACE,      // } 右大括号
    K_LPAREN,      // ( 左小括号
    K_RPAREN,      // ) 右小括号
    K_LBRACKET,    // [ 左中括号
    K_RBRACKET,    // ] 右中括号
    K_DOT,         // . 点号
    K_COMMA,       // , 逗号
    K_LT,          // < 小于
    K_GT,          // > 大于

    // 比较运算符 (双字符)
    K_LTE,         // <= 小于等于
    K_GTE,         // >= 大于等于
    K_NOT_EQUAL,   // != 不等于
    K_EQUAL,       // == 等于

    // 逻辑运算符
    K_NOT,         // ! 逻辑非
    K_AND,         // && 逻辑与
    K_OR,          // || 逻辑或

    // 算术运算符 - 赋值类
    K_ASSIGN,      // = 赋值
    K_PLUS_ASSIGN, // += 加赋值
    K_MINUS_ASSIGN,// -= 减赋值
    K_MUL_ASSIGN,  // *= 乘赋值
    K_DIV_ASSIGN,  // /= 除赋值
    K_MOD_ASSIGN,  // %= 模赋值

    // 算术运算符 - 基础运算
    K_PLUS,        // + 加
    K_MINUS,       // - 减
    K_MUL,         // * 乘
    K_DIV,         // / 除
    K_MOD,         // % 模

    // 特殊符号 (复合/专用符号)
    K_QUESTION,    // ? 问号（三元运算符/可选链）
    K_COLON_COLON, // :: 作用域解析符（C++/Java风格）
    K_ARROW,       // -> 箭头（函数/lambda表达式）
    K_INCREMENT,   // ++ 自增
    K_DECREMENT,   // -- 自减
    K_AT,          // @ at符号
    K_COLON,       // : 冒号

    // 字面量 (数据值)
    K_IDENT,       // 标识符 (变量名/函数名等)
    K_INTEGER,     // 整数
    K_DECIMAL,     // 浮点数 (x.xx 格式)
    K_STR,         // 字符串 ("xxx" 或 'xxx')
    K_BOOLEAN,     // 布尔值 (true/false)

    // 关键字 - 条件控制
    K_IF,          // if
    K_ELSE,        // else
    K_SWITCH,      // switch
    K_CASE,        // case
    K_DEFAULT,     // default

    // 关键字 - 循环控制
    K_WHILE,       // while
    K_FOR,         // for
    K_DO,          // do
    K_BREAK,       // break
    K_CONTINUE,    // continue

    // 关键字 - 类型声明
    K_VOID,        // void
    K_INT,         // int
    K_CHAR,        // char
    K_FLOAT,       // float
    K_BOOL,        // bool

    // 关键字 - 类相关
    K_CLASS,       // class
    K_STATIC,      // static
    K_PUBLIC,      // public
    K_PROTECTED,   // protected
    K_PRIVATE,     // private
    K_EXTENDS,     // extends
    K_RETURN,      // return
    K_NEW,         // new
    K_SUPER,       // super
    K_SELF,        // self

    // 关键字 - 异常处理
    K_TRY,         // try
    K_CATCH,       // catch
    K_THROW,       // throw
    K_FINALLY,     // finally

    // 关键字 - 变量声明
    K_VAR,         // var
    K_LET,         // let
    K_CONST,       // const
    K_IMPORT,      // import
} K_TOKEN;

#endif // CODE_LEXER_H