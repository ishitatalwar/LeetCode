# Write your MySQL query statement below

SELECT DISTINCT(p1.email) FROM Person p1, Person p2
where p1.id<>p2.id and p1.email = p2.email