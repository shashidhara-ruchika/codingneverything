-- https://www.metacareers.com/profile/coding_practice_question/?problem_id=428011838726692&psid=600891527799620&practice_plan=0&p=DATA_ENG&b=0121222

 /*

 BACKGROUND:
 
 The following schema is a subset of a relational database of a grocery store
 chain. This chain sells many products of different product classes to its
 customers across its different stores. It also conducts many different
 promotion campaigns.
 
 The relationship between the four tables we want to analyze is depicted below:
 
       # sales                                # products
       +------------------+---------+         +---------------------+---------+
       | product_id       | INTEGER |>--------| product_id          | INTEGER |
       | store_id         | INTEGER |    +---<| product_class_id    | INTEGER |
       | customer_id      | INTEGER |    |    | brand_name          | VARCHAR |
  +---<| promotion_id     | INTEGER |    |    | product_name        | VARCHAR |
  |    | store_sales      | DECIMAL |    |    | is_low_fat_flg      | TINYINT |
  |    | store_cost       | DECIMAL |    |    | is_recyclable_flg   | TINYINT |
  |    | units_sold       | DECIMAL |    |    | gross_weight        | DECIMAL |
  |    | transaction_date | DATE    |    |    | net_weight          | DECIMAL |
  |    +------------------+---------+    |    +---------------------+---------+
  |                                      |
  |    # promotions                      |    # product_classes
  |    +------------------+---------+    |    +---------------------+---------+
  +----| promotion_id     | INTEGER |    +----| product_class_id    | INTEGER |
       | promotion_name   | VARCHAR |         | product_subcategory | VARCHAR |
       | media_type       | VARCHAR |         | product_category    | VARCHAR |
       | cost             | DECIMAL |         | product_department  | VARCHAR |
       | start_date       | DATE    |         | product_family      | VARCHAR |
       | end_date         | DATE    |         +---------------------+---------+
       +------------------+---------+

 */ 
 /*
 PROMPT:
 -- What percent of all products in the grocery chain's catalog
 -- are both low fat and recyclable?
 

 EXPECTED OUTPUT:
 Note: Please use the column name(s) specified in the expected output in your solution.
 +----------------------------+
 | pct_low_fat_and_recyclable |
 +----------------------------+
 |         15.384615384615385 |
 +----------------------------+

 -------------- PLEASE WRITE YOUR SQL SOLUTION BELOW THIS LINE ---------------- 
 */

select (count(*) * 100.0)  / (select count(*) from products) as pct_low_fat_and_recyclable
from products
where is_low_fat_flg > 0 and is_recyclable_flg > 0;


select 100.0 * sum(is_low_fat_and_recyclable) / count(*)
from
(
select product_id, 
case
  when is_low_fat_flg > 0 and is_recyclable_flg > 0 then 1.0
  else 0.0
end as is_low_fat_and_recyclable
from products
) as pct_low_fat_and_recyclable;


 /*
 PROMPT:
 -- What are the top five (ranked in decreasing order)
 -- single-channel media types that correspond to the most money
 -- the grocery chain had spent on its promotional campaigns?

 Single Media Channel Types are promotions that contain only one media type.

 EXPECTED OUPTUT:
 Note: Please use the column name(s) specified in the expected output in your solution.
 +---------------------------+------------+
 | single_channel_media_type | total_cost |
 +---------------------------+------------+
 | In-Store Coupon           | 70800.0000 |
 | Street Handout            | 70627.0000 |
 | Radio                     | 60192.0000 |
 | Sunday Paper              | 56994.0000 |
 | Product Attachment        | 50815.0000 |
 +---------------------------+------------+
 
-------------- PLEASE WRITE YOUR SQL SOLUTION BELOW THIS LINE ----------------
 */

 select media_type as single_channel_media_type, sum(cost) as total_cost
 from promotions
 where media_type not like '%,%'
 group by media_type
 order by total_cost desc 
 limit 5;

 with RankedSingleChannelMediaType as (
 select media_type as single_channel_media_type,
 row_num() over ( partition by media_type order by cost desc ) as  mrank
 from promotions
 where media_type not like '%,%')
 select * 
 from RankedSingleChannelMediaType
 where row_num <= 5;


/*
 PROMPT:
 -- Of sales that had a valid promotion, the VP of marketing
 -- wants to know what % of transactions occur on either
 -- the very first day or the very last day of a promotion campaign.
 
 
 EXPECTED OUTPUT:
 Note: Please use the column name(s) specified in the expected output in your solution.
 +-------------------------------------------------------------+
 | pct_of_transactions_on_first_or_last_day_of_valid_promotion |
 +-------------------------------------------------------------+
 |                                         41.9047619047619048 |
 +-------------------------------------------------------------+
  
 -------------- PLEASE WRITE YOUR SQL SOLUTION BELOW THIS LINE ----------------
 */


select 100.0 * sum(valid_promotion) / count(*) as pct_of_transactions_on_first_or_last_day_of_valid_promotion
from
(
select p.promotion_id,
case 
  when s.transaction_date = p.start_date OR s.transaction_date = p.end_date THEN 1.0
  else 0.0
end as valid_promotion
from promotions p
join sales s
on p.promotion_id = s.promotion_id
);

 /*
 PROMPT
 -- The CMO is interested in understanding how the sales of different
 -- product families are affected by promotional campaigns.
 -- To do so, for each of the available product families,
 -- show the total number of units sold,
 -- as well as the ratio of units sold that had a valid promotion
 -- to units sold without a promotion,
 -- ordered by increasing order of total units sold.
 
 
 EXPECTED OUTPUT
 Note: Please use the column name(s) specified in the expected output in your solution.
 +----------------+------------------+--------------------------------------------------+
 | product_family | total_units_sold | ratio_units_sold_with_promo_to_sold_without_promo|
 +----------------+------------------+--------------------------------------------------+
 | Drink          |          43.0000 |                           0.79166666666666666667 |
 | Non-Consumable |         176.0000 |                           0.76000000000000000000 |
 | Food           |         564.0000 |                           0.75155279503105590062 |
 +----------------+------------------+--------------------------------------------------+
 
 -------------- PLEASE WRITE YOUR SQL SOLUTION BELOW THIS LINE ----------------
 */
 

-- TODO --

  /*
 PROMPT:
 -- The VP of Sales feels that some product categories don't sell
 -- and can be completely removed from the inventory.
 -- As a first pass analysis, they want you to find what percentage
 -- of product categories have never been sold.
 
 EXPECTED OUTPUT:
 Note: Please use the column name(s) specified in the expected output in your solution.
 +-----------------------------------+
 | pct_product_categories_never_sold |
 +-----------------------------------+
 |               13.8888888888888889 |
 +-----------------------------------+
 
 

 -------------- PLEASE WRITE YOUR SQL SOLUTION BELOW THIS LINE ----------------
 */

 select (1 - sum(is_product_category_sold) / ( select count(distinct product_category) from product_classes )) * 100 
 as pct_product_categories_never_sold
 from (
 select distinct pc.product_category, 
 case
    when s.product_id is null then 0.0
    else 1.0
 end as is_product_category_sold
 from products p
 join product_classes pc
 on pc.product_class_id = p.product_class_id
 left join sales s
 on s.product_id = p.product_id
 order by pc.product_class_id
  ) ;
