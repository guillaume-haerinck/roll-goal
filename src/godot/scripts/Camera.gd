extends Camera

onready var player : RigidBody = get_node("../Player")

var offset

func _ready():
	offset = translation - player.translation
	

func _physics_process(delta):
	translation = player.translation + offset
	
