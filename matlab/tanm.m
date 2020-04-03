function [output] = tan1(input)
%UNTITLED3 此处显示有关此函数的摘要
%   此处显示详细说明
    if input > 1048576.0 %输入大于2^20
		output = inf;
        return
    end
    if rem(input, 180) == 90
		output = inf;
        return
    end
    %对输入进行处理：使得输入在-90到+90范围内
    x = rem(input, 180);%将数轴上的点全部映射到-180到180上,此时x的取值范围为-180到180,需要再将其压缩为-90到90
    if x > 90
        x = x - 180;%将90-180上的点映射为-90-0
    elseif x < -90
        x = x + 180;%将-180--90的点映射为0-90
    end
    %常用特殊值
    if x == 45
        output = 1;
        return
    end
    if x == -45
        output = -1;
        return
    end

	pi = 3.14159265358979323846;
	y = x / 180 * pi;	%将角度输入转化为弧度输入

	output = y+  (1.0/3.0) * power(y,3) +  (2.0/15.0) * power(y,5) +  (17.0/315.0) * power(y,7)  +  (62.0/2835.0) * power(y,9) ;
 end