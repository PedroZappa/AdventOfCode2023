# #
# # User defined Commands (alias)
# #
define main
	display fd
	display line
end

define parse_line
	display /d len
	display /d EOL
	display /d win_i
	display /d num_i
	display /d win_nums
	display /d nums
	display /d line[len]
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
break parse_line
fs cmd
start

