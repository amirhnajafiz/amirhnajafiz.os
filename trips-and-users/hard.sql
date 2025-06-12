SELECT 
    T.request_at AS 'Day', 
    ROUND(SUM(T.status != 'completed') / COUNT(*), 2) AS 'Cancellation Rate'
FROM Trips T
JOIN Users C ON T.client_id = C.users_id AND C.banned = 'No'
JOIN Users D ON T.driver_id = D.users_id AND D.banned = 'No'
WHERE T.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY T.request_at;
