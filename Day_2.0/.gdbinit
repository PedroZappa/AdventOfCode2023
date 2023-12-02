define main
	display /d fd
	display /d n_games
	display /d sum
	display /s *line
	display games->id
	display games->round
	display games->next
end

define prs
	display curr_game
	display last_game
	display str_color
	display line_cp
	display /d id
	display /d n_cubes
	display /d i
	display /d j
	next
end

### gdb go!
break 36
run
main
fs cmd
