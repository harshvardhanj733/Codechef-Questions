# Write your MySQL query statement below
With cte1 as
(select * from students cross join subjects),

cte2 as
(select student_id, subject_name, count(student_id) as count
from examinations
group by student_id, subject_name)

select cte1.student_id, cte1.student_name, cte1.subject_name, coalesce(cte2.count, 0) as attended_exams
from cte1 left join cte2
on cte1.student_id = cte2.student_id
and cte1.subject_name = cte2.subject_name
order by cte1.student_id, cte1.subject_name;