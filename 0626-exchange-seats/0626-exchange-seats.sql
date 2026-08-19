# Write your MySQL query statement below
SELECT
    id,
    COALESCE(
        CASE
            WHEN id % 2 = 1 THEN LEAD(student) OVER (ORDER BY id)
            ELSE LAG(student) OVER (ORDER BY id)
        END,
        student
    ) AS student
FROM Seat;