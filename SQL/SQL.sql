/*
 175. Combine Two Tables
 Easy

 speed: 221 ms, faster than 61.93%
 memory: 0B, less than 100.00%

 https://leetcode.com/problems/combine-two-tables/
 */
SELECT
    Person.FirstName,
    Person.LastName,
    Address.City,
    Address.State
FROM
    Person LEFT JOIN Address
        ON Person.PersonId = Address.PersonId