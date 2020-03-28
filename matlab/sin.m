% 借助麦克劳林展开式对sin函数进行计算，注意输入x是角度
function [y] = sin1(x)

ORDER_NUM = 10; %麦克劳林展开的阶数

if x >= 360  %将输入规范至-360—360°之间
    x = x - floor(x / 360) * 360;
end
if x <= -360
    x = x + floor(- x / 360) * 360;
end

x = pi / 180 * x;  %将角度转化为弧度

y = 0;
for i = 1 : ORDER_NUM
    y = y + power(-1, i-1) * power(x, 2*i - 1) / factorial(2*i - 1);
end

end

