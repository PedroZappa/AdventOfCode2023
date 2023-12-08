# #
# # User defined Commands (alias)
# #
define main
	display /d i
	display /d n
	display fd
	display line
	display /d len
	display /d EOL
	display /d win_i
	display /d num_i
	display /d win_nums
	display /d win_nums[i]
	display /d nums
	display /d nums[n]
	display /d line[len]
	display /d card_points
	display /d total_points
end

define rfr
	refresh
end

define vgdb
	target remote | vgdb
end

define mchk
	monitor leak_check full reachable any
end

# #
# # Startup options
# #
set prompt (gdb-z)
set print pretty

set trace-commands on
set logging on
set logging overwrite


# #
# # Startup commands
# #
break 75
fs cmd
run
main

