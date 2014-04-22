这个工具可以帮助你打包出 WDF 文件.
方法是先制作一个 filename.lst 的文件.
每一行写上一个相对路径名的文件名
用 wdfpck filename
就可以打包成 filename.wdf
(在有 lst 文件的情况下, 可以用 wdfpck x filename 解开包)

在程序里, 用 WFile::OpenDataFile("filename.wdf");
就可以打开.
以后 WFile::Open("filename/xxxx");
就可以打开 filename.wdf 里的 xxxx 文件
注意, 这里只能用 / 而不能用\\, 第一个 / 将作为数据文件和子文件的分割符.
比如 WFile::Open("path\\datafile/xxxx"); 这样写

当然, 如果存在 path\filename\xxxx 这个文件, 将优先打开这个文件, 而不是数据包里的.
