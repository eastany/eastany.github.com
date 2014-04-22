/*
 "               ..;;;;,                     ;;;,    
 '           ..;;;"` ;;:           ,;;;;;: ,;;;:.,;..          _/
 `     ,;..,;;"`    :;;'            :;;"`,;;;;;;"":;;         _/ 
       ;;;"  `:;;. ;;'           ..;;:  .;;,.;;:',;;"    _/_/_/_/_/
      .;;`   ,;;" .;"          ,;;;;;;" :;`',;",;;"         _/
     ,;;,:.,;;;  ,;:          :" ,;:` , `:.;;;;;'`         _/   
     ;;"'':;;:. .;; .          ,;;;,;:;;,;;;, ,;             _/
    :;;..;;;;;; :;' :.        :;;;"` `:;;;;;,;,.;.          _/
  .;;":;;`  '"";;:  ';;       '""   .;;`.;";:;;;;` ;,  _/_/_/_/_/
 ;;;" `'       "::. ,;;:          .;"`  ::. '   .,;;;     _/ 
 ""             ';;;;;;;"        ""     ';;;;;;;;;;`     _/
 
                        Windsoul++

                by 云风 (Cloud Wu)  1999-2001
 
		http://member.netease.com/~cloudwu 
		mailto:cloudwu@263.net
 
		请阅读 readme.txt 中的版权信息
		See readme.txt for copyright information.

		Description:		指针映射
 		Original Author:	云风
		Authors:
		Create Time:		2000/12/12
		Modify Time:

.:*W*:._.:*I*:._.:*N*:._.:*D*:._.:*S*:._.:*O*:._.:*U*:._.:*L*:._.:*/

#ifndef _MAP_PTR2PTR_H
#define _MAP_PTR2PTR_H

class WMapPtr {
	enum {blocksize=2};
	int size;							// 空间大小
	int num;							// 现有元素个数
	void **ptr;							// 指针空间
public:
	WMapPtr() : size(blocksize), num(0) ,ptr(new void*[blocksize*2]) {};
	~WMapPtr() { delete []ptr; }
	void * LookUp(void *) const;		// 查找指针
	void Insert(void *key,void *var);	// 增加指针 [key]=var
	void Delete(void *);				// 删除指针
};

#endif