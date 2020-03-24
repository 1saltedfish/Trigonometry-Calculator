% �����������չ��ʽ��sin�������м��㣬ע������x�ǽǶ�
function [y] = sin1(x)

ORDER_NUM = 10; %�������չ���Ľ���

if x >= 360  %������淶��-360��360��֮��
    x = x - floor(x / 360) * 360;
end
if x <= -360
    x = x + floor(- x / 360) * 360;
end

x = pi / 180 * x;  %���Ƕ�ת��Ϊ����

y = 0;
for i = 1 : ORDER_NUM
    y = y + power(-1, i-1) * power(x, 2*i - 1) / factorial(2*i - 1);
end

end

