function [y] = sin1(x)
% �����������չ��ʽ��sin�������м���
ORDER_NUM = 100; %չ���Ľ���
y = 0;

for i = 1 : ORDER_NUM
    %y = y + (-1)^(i-1) * x^(2*i - 1) / factorial(2*i - 1);  
    y = y + power(-1, i-1) * power(x, 2*i - 1) / factorial(2*i - 1);
end

end

