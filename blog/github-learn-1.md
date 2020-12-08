---
title: github操作-1
date: 2020-06-05 20:20:06
tags: github linux
---
# github上传文件
遇到github需要上传文件时有两种上传方式
1. github网站在线上传，且github不支持上传空文件夹，所以必须在里面加上一个文件(一般情况下为.md文件)
2. github本地仓库移动，一般认定为linux系统上操作\
<!-- more -->
同步远程仓库
```
    $ git add -a
    $ git commit -m "Update"
    $ git push origin master
```
# github同步文件
所需要执行操作
```
    $ git pull origin master
```
# github移动文件
1-此为文件移动到文件夹内\
2-此为文件夹移动另一个文件夹内
```
    $ git mv file.txt tmp/    
    $ git mv tmp1 tmp2/   
```
-----------------------
# 总结
GitHub平时不常用的后果就是上传出现问题就会导致操作半条不清楚怎么处理\
以上





