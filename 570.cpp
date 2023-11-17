# Write your MySQL query statement below

with cte1 as
(
  select managerId, count(managerId) as count
  from employee
  group by managerId
)

select name from employee left join cte1
on employee.id = cte1.managerId
where cte1.count >= 5;