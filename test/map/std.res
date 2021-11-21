mp contains:
1 => 3
2 => 6
3 => 9
4 => 12
5 => 15
6 => 18
7 => 21
8 => 24
9 => 27
10 => 30
size = 10
------------------------

	-- [0] (const) --
with key [-10]:
lower_bound: key: 1 | value: 3
upper_bound: key: 1 | value: 3
equal_range: 1
	-- [1] (const) --
with key [1]:
lower_bound: key: 1 | value: 3
upper_bound: key: 2 | value: 6
equal_range: 1
	-- [2] (const) --
with key [5]:
lower_bound: key: 5 | value: 15
upper_bound: key: 6 | value: 18
equal_range: 1
	-- [3] (const) --
with key [10]:
lower_bound: key: 10 | value: 30
upper_bound: end()
equal_range: 1
	-- [4] (const) --
with key [50]:
lower_bound: end()
upper_bound: end()
equal_range: 1
mp contains:
1 => 3
2 => 6
3 => 9
4 => 12
5 => 15
6 => 18
7 => 21
8 => 24
9 => 27
10 => 30
size = 10
------------------------

	-- [5] --
with key [5]:
lower_bound: key: 5 | value: 15
upper_bound: key: 6 | value: 18
equal_range: 1
	-- [6] --
with key [7]:
lower_bound: key: 7 | value: 21
upper_bound: key: 8 | value: 842
equal_range: 1
mp contains:
1 => 3
2 => 6
3 => 404
4 => 12
5 => 15
6 => 18
7 => 21
8 => 842
9 => 27
10 => 30
size = 10
------------------------

