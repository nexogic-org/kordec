<center><h1>Nexogic Kordec</h1></center>

---

<p align="center">
  <b>⚠️ 正在制作中 (WIP) ⚠️</b><br>
  <i>本项目目前处于极早期的开发阶段。在此阶段所做的任何更改、功能或代码实现均不保证稳定性或可用性，且作者不对因使用本仓库代码而导致的任何后果承担任何责任。</i>
</p>

---

> Kordec 开发了 Kordec 编程语言及其配套工作流，具有优雅的语法和对面向对象编程 (OOP) 的全面支持。
>
> 作为 Korelin 的重构继承版，它在语法层面保持了大部分的后向兼容，但通过强制纯面向对象范式，将过程式代码结构全面转型为基于类和消息传递的编程模型。

<p align="center">
  <img src="kordec.svg" alt="Kordec LOGO" width="80">
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

- **高性能运行时**: 使用的 **Vector 引擎** 执行，并集成 **Jitter JIT** 即时编译技术，确保在处理复杂逻辑与大规模数据时保持卓越的执行效率。
- **纯面向对象 (Pure OOP)**: 强制所有代码基于类和对象构建，消除全局函数和过程式结构的混乱。
- **消息传递模型**: 借鉴 Smalltalk 的核心思想，对象之间通过发送消息进行交互，增强解耦与灵活性。
- **现代化工作流**: 内置 CLI 工具，支持项目初始化、编译、打包及包管理。
- **C 扩展支持**: 提供更加底层的 API 接口，方便开发者使用 C 语言为 Kordec 编写高性能扩展模块。

## 项目结构

```text
src/
├── api/              # 外部调用接口 (FFI)
├── cli/              # 命令行交互与工具链实现
├── codegen/          # 目标代码生成器
├── ir/               # 向量化中间表示 (Vector IR)
├── lexer/            # 高效词法分析器
├── optimizer/        # 代码优化器
├── parser/           # 语法分析器与 AST 构建
├── preprocessing/    # 包管理与预处理器
├── runtime/          # 运行时支持
│   ├── gc/           # 增量式垃圾回收器
│   └── stdlib/       # 标准库 (Console, IO, Net, JSON, Math 等)
├── semantic/         # 语义分析与类型校验
├── vector/           # 核心执行引擎
│   └── jitter/       # Jitter JIT 即时编译器
├── const.h           # 全局常量定义
└── main.c            # 程序入口
```

## 快速开始

```kordec
// main.kd
import console;

class test {
    public static void main() {
        console.println("Hello, World!");
    }
}
```

### 编译项目

确保你的环境中已安装 CMake 和 C 编译器（如 GCC 或 MSVC）：

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### 运行 Kordec

```bash
# 运行脚本
./kordec run main.kd

# 查看帮助信息
./kordec help

# 初始化新项目
./kordec init my_project
```

## 针对 Korelin 核心缺陷的深度优化

作为继承者，Kordec 针对前作 Korelin 在工程实践中暴露的系统级缺陷进行了底层重构与优化：

- **模块化包管理寻址失效问题**
  - **缺陷描述**: Korelin 在处理复杂嵌套结构的包引用时，常因相对路径计算偏移导致符号解析失败。
  - **优化方案**: 引入了确定性的包搜索路径算法与绝对路径缓存机制，支持递归依赖解析，确保多层级项目结构的稳定性。
- **虚拟机内存安全性与 GC 效能瓶颈**
  - **缺陷描述**: Korelin 虚拟机在深度递归或大数据量处理时易发生栈溢出，且其垃圾回收机制对瞬时大量对象的回收响应滞后。
  - **优化方案**: 重构了虚拟机核心调度器，优化了调用栈内存布局，并引入了改进的增量式标记-清除 (Incremental Mark-and-Sweep) 垃圾回收算法，显著提升了高并发场景下的内存吞吐量。
- **C 语言扩展接口 (FFI) 的不稳定性**
  - **缺陷描述**: 原有的 C 扩展机制缺乏严格的类型约束与边界检查，导致原生模块调用极易崩溃。
  - **优化方案**: 规范化了原生扩展的语义标准，提供了更加底层的内存访问安全屏障与自动化的类型映射机制，降低了标准库与第三方扩展的维护成本。
- **过程式编码模式导致的架构混乱**
  - **缺陷描述**: 过程式代码在大型工程中难以解耦，导致逻辑碎片化且难以维护。
  - **优化方案**: 强制推行“万物皆对象”的纯 OOP 范式，通过类抽象与消息传递 (Message Passing) 机制重塑业务逻辑，从根本上提升了代码的工程化可维护性。

## 路线图 (Roadmap)

- [x] 核心虚拟机架构重构
- [x] 纯面向对象语法解析支持
- [x] 基础 CLI 工具链实现
- [x] JIT (即时编译) 引擎深度优化
- [ ] 跨平台图形化标准库支持
- [ ] 自动化包分发平台 (Kordec Registry)

<p align="center">
  <img src="https://nexogic.org/favicon.ico" alt="Nexogic Logo" width="16" style="vertical-align: middle;">
  <br>
  Copyright (c) 2026 Nexogic. Released under Apache 2.0 License.
</p>