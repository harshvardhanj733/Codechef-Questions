# Write your MySQL query statement below
with c1 as (
    select customer_id, rank() over(partition by customer_id order by order_date) as order_rank, case when order_date = customer_pref_delivery_date then 'I' else 'S' end as del_type from delivery
)

select round(sum(case when del_type = 'I' then 1 else 0 end) * 100/ coalesce(count(*), 1), 2) as immediate_percentage from c1 where order_rank = 1;