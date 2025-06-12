# Write your MySQL query statement below
SELECT Email FROM (
    SELECT email as Email, COUNT(id) as EmailCount
    FROM Person
    GROUP BY email
) AS Counts
WHERE EmailCount > 1;
