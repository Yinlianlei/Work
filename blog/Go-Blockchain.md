---
title: Go-Blockchain
date: 2020-10-15 00:39:24
tags:
---
# 今日在搞区块链和数据库的时候遇到的问题：
## mysql最开始的时候出现了ERROR(2800)的问题：
解决办法:\
<!-- more -->
* 在my.cnf中设置skip-grant-tables，之后再关闭mysql服务
```
$ service mysql stop
```
* 之后进入root权限对root密码进行修改。由于kali linux自带的mysql使无密码进入，可以再root权限内直接进入修改权限
* 疑似是kali linux自带mysql可由root权限直接进入
```
# mysql -u root
EnterPassword: //回车键
```
* 之后更改密码和添加用户
```
alter user 'root'@'localhost' identified by 'toor';
create user 'Yinlianlei'@'localhost' identified by 'Password';
```
* 然后重新更改用户再登陆即可
---------------------------
## 然后就是一个很该死的还原问题了，Go环境变量修改
```
$ sudo vim /etc/profile

//末尾加上

export PATH=$PATH:/usr/local/go/bin

$ reboot
```
重启后即可完成
======================

# 好吧区块链的服务块目前出现问题到此，还有微信小程序和机械学习要搞，感觉要累到猝死。

以上
