extends RigidBody

const MAX_VELOCITY = 100

func _physics_process(delta):
	var force := Vector3.ZERO
	
	if Input.is_action_pressed("ui_up"):
		force.z = -1
	elif Input.is_action_pressed("ui_down"):
		force.z = 1
		
	if Input.is_action_pressed("ui_left"):
		force.x = -1
	elif Input.is_action_pressed("ui_right"):
		force.x = 1
		
	if force == Vector3.ZERO:
		force -= linear_velocity / 2
		
	if linear_velocity.length_squared() < MAX_VELOCITY:
		add_force(force, transform.origin)
	
