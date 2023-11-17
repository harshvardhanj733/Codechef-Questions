# Write your MySQL query statement below
with cte1 as
(
    select user_id, count(user_id) as count_action
    from confirmations
    group by user_id
),

cte2 as
(
    select user_id, count(user_id) as count_confirmed
    from confirmations
    where action = 'confirmed'
    group by user_id
)

select signups.user_id, round(coalesce(cte2.count_confirmed, 0)/coalesce(cte1.count_action, 1), 2) as confirmation_rate from (signups left join cte1 on signups.user_id = cte1.user_id) left join cte2 on signups.user_id = cte2.user_id;