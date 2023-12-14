define main
	display *line
	display *time
	display *distance
	display fd
end

define get_time
	display *line
	display **time
end

define get_distance
	display *line
	display **distance
end


### Startup Commands
set logging on
set trace-commands on
fs cmd

