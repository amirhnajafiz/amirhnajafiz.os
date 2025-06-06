DELETE FROM Person
WHERE id NOT IN (
    SELECT id FROM (
        SELECT MIN(id) as id
        FROM Person
        GROUP BY email
    ) AS latest_ids
);
