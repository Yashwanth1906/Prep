## SQL Things to remember

- IS keyword is uesd to map to null values in a field.
- LIKE Keyword is used to match patterns in string like 'C%' takes all the words starting with 'C'.
- concat keyword is used to concatenate column values and normal values.
- count keyword is used to count the no of entries.
- (1....10) we can put elements and put in to check where id is present in the tuple or not.
- To get the year from the Date type in SQL we need to use YEAR(dob).

### Select Query Syntax:
- SELECT field1 as name1, .... from table_name where condition;

### Update Query syntax:
- UPDATE table_name SET column1 = value1, column2 = value2, ... WHERE condition;


## SQL Joins - Description and Syntax

### 1. INNER JOIN

**Description:**  
Returns only the rows where there is a match in both tables.

**Syntax:**
```sql
SELECT columns
FROM TableA
INNER JOIN TableB ON TableA.common_column = TableB.common_column;
```

### 2. LEFT JOIN (or LEFT OUTER JOIN)

Description:
Returns all rows from the left table and the matched rows from the right table. If no match, NULLs are returned from the right side.

Syntax:

```sql
SELECT columns
FROM TableA
LEFT JOIN TableB ON TableA.common_column = TableB.common_column;
```

### 3. RIGHT JOIN (or RIGHT OUTER JOIN)

Description:
Returns all rows from the right table and the matched rows from the left table. If no match, NULLs are returned from the left side.

Syntax:

```sql
SELECT columns
FROM TableA
RIGHT JOIN TableB ON TableA.common_column = TableB.common_column;
```
### 4. FULL JOIN (or FULL OUTER JOIN)

Description:
Returns all rows when there is a match in one of the tables. If there is no match, NULLs are returned from the table without a match.

Syntax:

```sql
SELECT columns
FROM TableA
FULL OUTER JOIN TableB ON TableA.common_column = TableB.common_column;
```
### 5. CROSS JOIN

Description:
Returns the Cartesian product of both tables—each row in the first table is combined with every row in the second table.

Syntax:

```sql
SELECT columns
FROM TableA
CROSS JOIN TableB;
```