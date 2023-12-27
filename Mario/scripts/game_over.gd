extends Node2D

@onready var music = $music
@onready var active = $active
@onready var hover = $hover

func _process(delta):
	if Global.is_sounds_on == true:
		music.volume_db = 0
	else:
		music.volume_db = -80
		

func _on_continue_pressed():
	if Global.is_sounds_on == true:
		active.play()
		await active.finished
	get_tree().change_scene_to_file("res://levels/main_level.tscn")

func _on_exit_pressed():
	if Global.is_sounds_on == true:
		active.play()
		await active.finished
	queue_free()


func _on_continue_mouse_entered():
	if Global.is_sounds_on == true:
		hover.play()


func _on_exit_mouse_entered():
	if Global.is_sounds_on == true:
		hover.play()
