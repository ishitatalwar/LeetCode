# Write your MySQL query statement below
SELECT Max(num) as num from MyNumbers WHERE num in (select num from MyNumbers group by num having count(*) = 1);