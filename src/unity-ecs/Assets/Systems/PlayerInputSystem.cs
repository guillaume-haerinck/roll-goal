using UnityEngine;
using Unity.Jobs;
using Unity.Entities;
using Unity.Mathematics;
using UnityEngine.InputSystem;

[AlwaysSynchronizeSystem]
public class PlayerInputSystem : JobComponentSystem
{
    protected override JobHandle OnUpdate(JobHandle inputDeps)
    {
        float z = (Keyboard.current.upArrowKey.isPressed ? 1 : 0) + (Keyboard.current.downArrowKey.isPressed ? -1 : 0);
        float x = (Keyboard.current.rightArrowKey.isPressed ? 1 : 0) + (Keyboard.current.leftArrowKey.isPressed ? -1 : 0);

        Entities.ForEach((ref MotionComponent motion) => {
            motion.direction = new float3(x, 0f, z);
        }).Run();

        return default;
    }
}
