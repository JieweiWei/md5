md5
===


用c++实现md5算法.


开发平台
========


Ubuntu14.04


运行
====


sudo get-apt install g++

make

./md5_test


md5简介
=======


消息摘要算法第五版（英语：Message-Digest Algorithm 5，缩写为MD5），是当前计算机领域用于确保信息传输完整一致而广泛使用的散列算法之一（又译哈希算法、摘要算法等），主流编程语言普遍已有MD5的实现。将数据
（如一段文字）运算变为另一固定长度值，是散列算法的基础原理，MD5的前身有MD2、MD3和MD4。MD5由MD4、MD3、MD2改进而来，主要增强算法复杂度和不可逆性。目前，MD5算法因其普遍、稳定、快速的特点，仍广泛应用于普通
数据的错误检查领域。例如在一些BitTorrent下载中，软件将通过计算MD5检验下载到的文件片段的完整性。MD5已经广泛使用在为文件传输提供一定的可靠性方面。例如，服务器预先提供一个MD5校验和，用户下载完文件以后，
用MD5算法计算下载文件的MD5校验和，然后通过检查这两个校验和是否一致，就能判断下载的文件是否出错。MD5是输入不定长度信息，输出固定长度128-bits的算法。经过程序流程，生成四个32位数据，最后联合起来成为一个
128-bits散列。基本方式为，求余、取余、调整长度、与链接变量进行循环运算。得出结果。


md5算法描述
===========


假设输入信息(input message)的长度为b(bit)，我们想要产生它的报文摘要，在此处b为任意的非负整数：b也可能为0，也不一定为8的整数倍，且可能是任意大的长度。设该信息的比特流表示如下：
          M[0] M[1] M[2] ... M[b-1]
计算此信息的报文摘要需要如下5步：

1.补位
------

信息计算前先要进行位补位，设补位后信息的长度为LEN(bit)，则LEN%512 = 448(bit)，即数据扩展至
K * 512 + 448(bit)。即K * 64+56(byte)，K为整数。补位操作始终要执行，即使补位前信息的长度对512求余的结果是448。具体补位操作：补一个1，然后补0至满足上述要求。总共最少要补1bit，最多补512bit。

2.尾部加上信息长度
------------------

将输入信息的原始长度b(bit)表示成一个64-bit的数字，把它添加到上一步的结果后面(在32位的机器上，这64位将用2个字来表示并且低位在前)。当遇到b大于2^64这种极少的情况时，b的高位被截去，仅使用b的低64位。经过上面两步，数据就被填补成长度为512(bit)的倍数。也就是说，此时的数据长度是16个字(32byte)的整数倍。此时的数据表示为：
          M[0 ... N-1]
其中的N是16的倍数。

3.初始化缓存区
--------------

用一个四个字的缓冲器(A，B，C，D)来计算报文摘要，A,B,C,D分别是32位的寄存器，初始化使用的是十六进制表示的数字，注意低字节在前：
        word A: 01 23 45 67
        word B: 89 ab cd ef
        word C: fe dc ba 98
        word D: 76 54 32 10

4.转换
-------

首先定义4个辅助函数，每个函数的输入是三个32位的字，输出是一个32位的字：
        F(X,Y,Z) = XY v not(X) Z
        G(X,Y,Z) = XZ v Y not(Z)
        H(X,Y,Z) = X xor Y xor Z
        I(X,Y,Z) = Y xor (X v not(Z))

        FF(a,b,c,d,Mj,s,ti）表示 a = b + ((a + F(b,c,d) + Mj + ti) << s)
        GG(a,b,c,d,Mj,s,ti）表示 a = b + ((a + G(b,c,d) + Mj + ti) << s)
        HH(a,b,c,d,Mj,s,ti）表示 a = b + ((a + H(b,c,d) + Mj + ti) << s)
        Ⅱ（a,b,c,d,Mj,s,ti）表示 a = b + ((a + I(b,c,d) + Mj + ti) << s)
这四轮（64步）是：

第一轮

FF(a,b,c,d,M0,7,0xd76aa478）
FF(d,a,b,c,M1,12,0xe8c7b756）
FF(c,d,a,b,M2,17,0x242070db)
FF(b,c,d,a,M3,22,0xc1bdceee)
FF(a,b,c,d,M4,7,0xf57c0faf)
FF(d,a,b,c,M5,12,0x4787c62a)
FF(c,d,a,b,M6,17,0xa8304613）
FF(b,c,d,a,M7,22,0xfd469501）
FF(a,b,c,d,M8,7,0x698098d8）
FF(d,a,b,c,M9,12,0x8b44f7af)
FF(c,d,a,b,M10,17,0xffff5bb1）
FF(b,c,d,a,M11,22,0x895cd7be)
FF(a,b,c,d,M12,7,0x6b901122）
FF(d,a,b,c,M13,12,0xfd987193）
FF(c,d,a,b,M14,17,0xa679438e)
FF(b,c,d,a,M15,22,0x49b40821）

第二轮

GG(a,b,c,d,M1,5,0xf61e2562）
GG(d,a,b,c,M6,9,0xc040b340）
GG(c,d,a,b,M11,14,0x265e5a51）
GG(b,c,d,a,M0,20,0xe9b6c7aa)
GG(a,b,c,d,M5,5,0xd62f105d)
GG(d,a,b,c,M10,9,0x02441453）
GG(c,d,a,b,M15,14,0xd8a1e681）
GG(b,c,d,a,M4,20,0xe7d3fbc8）
GG(a,b,c,d,M9,5,0x21e1cde6）
GG(d,a,b,c,M14,9,0xc33707d6）
GG(c,d,a,b,M3,14,0xf4d50d87）
GG(b,c,d,a,M8,20,0x455a14ed)
GG(a,b,c,d,M13,5,0xa9e3e905）
GG(d,a,b,c,M2,9,0xfcefa3f8）
GG(c,d,a,b,M7,14,0x676f02d9）
GG(b,c,d,a,M12,20,0x8d2a4c8a)

第三轮

HH(a,b,c,d,M5,4,0xfffa3942）
HH(d,a,b,c,M8,11,0x8771f681）
HH(c,d,a,b,M11,16,0x6d9d6122）
HH(b,c,d,a,M14,23,0xfde5380c)
HH(a,b,c,d,M1,4,0xa4beea44）
HH(d,a,b,c,M4,11,0x4bdecfa9）
HH(c,d,a,b,M7,16,0xf6bb4b60）
HH(b,c,d,a,M10,23,0xbebfbc70）
HH(a,b,c,d,M13,4,0x289b7ec6）
HH(d,a,b,c,M0,11,0xeaa127fa)
HH(c,d,a,b,M3,16,0xd4ef3085）
HH(b,c,d,a,M6,23,0x04881d05）
HH(a,b,c,d,M9,4,0xd9d4d039）
HH(d,a,b,c,M12,11,0xe6db99e5）
HH(c,d,a,b,M15,16,0x1fa27cf8）
HH(b,c,d,a,M2,23,0xc4ac5665）

第四轮

Ⅱ（a,b,c,d,M0,6,0xf4292244）
Ⅱ（d,a,b,c,M7,10,0x432aff97）
Ⅱ（c,d,a,b,M14,15,0xab9423a7）
Ⅱ（b,c,d,a,M5,21,0xfc93a039）
Ⅱ（a,b,c,d,M12,6,0x655b59c3）
Ⅱ（d,a,b,c,M3,10,0x8f0ccc92）
Ⅱ（c,d,a,b,M10,15,0xffeff47d)
Ⅱ（b,c,d,a,M1,21,0x85845dd1）
Ⅱ（a,b,c,d,M8,6,0x6fa87e4f)
Ⅱ（d,a,b,c,M15,10,0xfe2ce6e0)
Ⅱ（c,d,a,b,M6,15,0xa3014314）
Ⅱ（b,c,d,a,M13,21,0x4e0811a1）
Ⅱ（a,b,c,d,M4,6,0xf7537e82）
Ⅱ（d,a,b,c,M11,10,0xbd3af235）
Ⅱ（c,d,a,b,M2,15,0x2ad7d2bb)
Ⅱ（b,c,d,a,M9,21,0xeb86d391）


参考
====


http://zh.wikipedia.org/zh/MD5
http://baike.baidu.com/view/7636.htm?fromtitle=MD5%E7%AE%97%E6%B3%95&fromid=174909&type=syn
http://www.cppblog.com/ant/archive/2007/09/11/31886.html

