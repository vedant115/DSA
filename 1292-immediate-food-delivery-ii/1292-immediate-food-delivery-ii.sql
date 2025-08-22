SELECT ROUND(SUM(order_date = customer_pref_delivery_date) * 100.00 / COUNT(delivery_id), 2) immediate_percentage 
FROM Delivery 
WHERE (customer_id, order_date) IN
    (SELECT customer_id, MIN(order_date) 
    AS first_order_date
    FROM Delivery
    GROUP BY customer_id);