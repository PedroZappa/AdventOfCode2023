define main
	display /d hands
	display /d bids
	display /d winnings
	display /d fd
end

define parse_line
	display line
	display hands
	display bids
	display /d bids
	display /d i
end


### Debugger Startup ###
set logging on
set trace-commands on
fs cmd

