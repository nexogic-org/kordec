<center><h1>Nexogic Kordec</h1></center>

> Kordec 开发了 Kordec 编程语言及其配套工作流，具有优雅的语法和对面向对象编程 (OOP) 的全面支持。
>
> 作为 Korelin 的重构继承版，它在语法层面保持了大部分的后向兼容，但通过强制纯面向对象范式，将过程式代码结构全面转型为基于类和消息传递的编程模型。

<p align="center">
  <img src="logo.png" alt="Kordec LOGO" width="80">
  <br>
  <b>Kordec LOGO</b>
  <br>
  <a href="https://github.com/nexogic-org/kordec/blob/main/LICENSE"><img src="https://img.shields.io/badge/License-Apache_2.0-blue.svg" alt="License"></a>
  <a href="https://github.com/nexogic-org/kordec"><img src="https://img.shields.io/badge/GitHub-nexogic--org%2Fkordec-lightgrey?logo=github" alt="GitHub"></a>
  <img src="https://img.shields.io/github/stars/nexogic-org/kordec?style=social" alt="Stars">
  <img src="https://img.shields.io/badge/v0.1.0-lightgrey" alt="Version">
  <img src="https://img.shields.io/badge/Author-Nexogic-purple" alt="Author">
</p>


## 核心特性

- **纯面向对象 (Pure OOP)**: 强制所有代码基于类和对象构建，消除全局函数和过程式结构的混乱。
- **消息传递模型**: 借鉴 Smalltalk 的核心思想，对象之间通过发送消息进行交互，增强解耦与灵活性。
- **高性能运行时**: 采用 C 语言编写的底层虚拟机，具备高效的垃圾回收 (GC) 和即时编译 (JIT) 潜力。
- **现代化工作流**: 内置 CLI 工具，支持项目初始化、编译、打包及包管理。
- **C 扩展支持**: 提供更加底层的 API 接口，方便开发者使用 C 语言为 Kordec 编写高性能扩展模块。

## 项目结构

```text
src/
├── api/          # 外部调用接口
├── cli/          # 命令行工具实现
├── codegen/      # 代码生成器
├── ir/           # 中间表示处理
├── lexer/        # 词法分析器
├── parser/       # 语法分析器与 AST 构建
├── preprocessing/# 预处理与包管理
├── runtime/      # 虚拟机运行时与标准库
└── semantic/     # 语义分析器
```

## 快速开始

### 编译项目

确保你的环境中已安装 CMake 和 C 编译器（如 GCC 或 MSVC）：

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### 运行 Kordec

```bash
# 查看帮助信息
./kordec help

# 初始化新项目
./kordec init my_project
```

## 解决的Korelin Bug

- Korelin 包管理寻址错误
  - 解决方案: 加强处理逻辑
- Korelin 虚拟机容易溢出,gc不强力
  - 解决方案: 重构地底层代码
- Korelin 对于C的扩展易出错,标准库试验性强
  - 解决方案: 新增语法, 将c扩展结构开放更加底层
- Korelin 代码可读性不强
  - 解决方案: 将过程式代码结构全面转型为基于类和消息传递的编程模型。

<p align="center">
  <img src="https://nexogic.org/favicon.ico" alt="Nexogic Logo" width="16" style="vertical-align: middle;">
  <br>
  Copyright (c) 2026 Nexogic. Released under Apache 2.0 License.
</p>