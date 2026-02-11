<center><h1>Nexogic Kordec</h1></center>

> Kordec作为Korelin的重构继承版,继承了大部分的语法,
> 但通过强制纯面向对象范式，将过程式代码结构全面转型为基于类和消息传递的编程模型。

<div style="margin: 20px auto; display: flex; flex-direction: column; justify-content: center; align-items: center; gap: 6px;">
   <img src="logo.png" alt="logo" style="width:80px; border-radius:6px; box-shadow:0 2px 4px rgba(0,0,0,0.1);">
   <b><span style="font-size: 14px; color: #333; text-align: center;">Kordec LOGO</span></b>
   <div style="display: flex; flex-wrap: wrap; justify-content: center; align-items: center; gap: 6px; margin-top: 8px; max-width: 100%;">
      <img src="https://img.shields.io/badge/License-Apache_2.0-blue.svg" alt="Apache 2.0 License" style="height: 20px; vertical-align: middle;">
      <a href="https://github.com/nexogic-org/kordec" target="_blank" style="text-decoration: none; display: inline-flex; align-items: center;">
         <img src="https://img.shields.io/badge/GitHub-nexogic--org%2Fkordec-lightgrey.svg?logo=github" alt="GitHub Repository" style="height: 20px; vertical-align: middle;">
      </a>
<img src="https://img.shields.io/github/stars/nexogic-org/kordec?style=social" alt="GitHub Stars" style="height: 20px; vertical-align: middle;">
      <img src="https://img.shields.io/tokei/lines/github/nexogic-org/kordec" alt="Code Lines" style="height: 20px; vertical-align: middle;">
      <img src="https://img.shields.io/badge/Author-Nexogic-purple.svg" alt="Author: Nexogic" style="height: 20px; vertical-align: middle;">
   </div>
</div>


## 解决的Bug

- Korelin 包管理寻址错误
  - 解决方案: 加强处理逻辑
- Korelin 虚拟机容易溢出,gc不强力
  - 解决方案: 重构地底层代码
- Korelin 对于C的扩展易出错,标准库试验性强
  - 解决方案: 新增语法, 将c扩展结构开放更加底层
- Korelin 代码可读性不强
  - 解决方案: 将过程式代码结构全面转型为基于类和消息传递的编程模型。

<hr>
<div class="footer" style="text-align: center; color: #666; font-size: 12px; margin-top: 40px; padding: 20px; border-top: 1px solid #eee;">
   Copyright (c) 2026 Nexogic. Released under Apache 2.0 License.
</div>