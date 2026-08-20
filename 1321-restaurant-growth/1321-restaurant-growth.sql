# Write your MySQL query statement below
SELECT
    DATE_ADD(c1.visited_on, INTERVAL 6 DAY) AS visited_on,
    SUM(c2.amount) AS amount,
    ROUND(SUM(c2.amount) / 7, 2) AS average_amount
FROM
(
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) c1
JOIN
(
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
) c2
ON c2.visited_on BETWEEN c1.visited_on
AND DATE_ADD(c1.visited_on, INTERVAL 6 DAY)
GROUP BY c1.visited_on
HAVING COUNT(DISTINCT c2.visited_on) = 7
ORDER BY visited_on;