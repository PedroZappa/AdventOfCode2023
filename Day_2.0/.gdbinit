define main
	display /d fd
	display /d n_games
	display /d sum
	display /s *line
	display games_list->id
	display games_list->rounds
	display games_list->rounds->red
	display games_list->rounds->green
	display games_list->rounds->blue
	display games_list->rounds->next->red
	display games_list->rounds->next->green
	display games_list->rounds->next->blue
	display games_list->next
end

define prs
	display line
	display *games_list
	display /c line[i]
	display /c line[i + j]
	display *curr_game
	display *curr_game->rounds
	display *curr_game->rounds->rounds
	display *curr_game->rounds->rounds->rounds
	display *last_game
	display line_cp
	display /d id
	display /d n_cubes
	display /d i
	display /d j
	next
end

### gdb go!
set trace-commands on
set logging on
break 160
run
# main
fs cmd
# step
prs
