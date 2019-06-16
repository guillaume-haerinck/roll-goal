extends Spatial

onready var player = get_node("Player")
var should_reset = true

func _on_Level1_game_over():
	should_reset = true

func _on_HUD_game_over():
	should_reset = true

func _on_Level1_win():
	should_reset = true

func _physics_process(delta):
	if should_reset:
		reset()

func reset():
	player.translation = $"Level-1/Start".translation
	player.translation.y += 0.2
	player.set_linear_velocity(Vector3.ZERO)
	should_reset = false
