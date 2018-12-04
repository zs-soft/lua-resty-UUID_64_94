 本工程在网上上某个项目工程的基础上添加了两个函数,忘记作者的地址与信息了,作者看到可联系本人。

调用系统的UUID模块生成的由32位16进制（0-f）数组成的的串，本模块进一步压缩为62进制。

```	
-- 生成8位UUID
local uuidx = require "resty.uuidx" 

local id =  uuidx.gen8()   --output 3uNy6ZzI


-- 生成20为UUID
local uuidx = require "resty.uuidx" 

local id =  uuidx.gen20() --2qYArunu73bABy2RqY3M

-- 生成64进制的uuid
local uuidx = require "resty.uuidx" 
local id =  uuidx.gen64hex() --2qYArunu73bABy2RqY3M'

-- 生成256进制的uuid
local uuidx = require "resty.uuidx" 
local uuid_str = uuidx.gen() -- uuid dd44dd16-bff4-454b-8f8b-8a624e988e23
local id =  uuidx.gen256hex(uuid_str) -- 由于是超过了ascii码 所以显示不正常，可以使用base64查看

```	
正如你所想，生成的UUID越长，理论冲突率就越小，请根据业务需要自行斟酌。
基本思想为把系统生成的16字节（128bit）的UUID转换为62进制（a-zA-Z0-9），同时根据业务需要进行截断。

-------------------------------------------
在原作者的基础上,拓展了64\94\128\256等进制的字符串生成,减少uuid的长度

