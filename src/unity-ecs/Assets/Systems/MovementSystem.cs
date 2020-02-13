using UnityEngine;
using Unity.Jobs;
using Unity.Entities;
using Unity.Mathematics;
using Unity.Transforms;
using Unity.Physics;
using Unity.Physics.Extensions;

public class MovementSystem : JobComponentSystem
{
    protected override JobHandle OnUpdate(JobHandle inputDeps)
    {
        float dt = Time.DeltaTime;

        JobHandle myJob = Entities.ForEach((ref PhysicsVelocity vel, in PhysicsMass mass, in MotionComponent motion) => {
            ComponentExtensions.ApplyLinearImpulse(ref vel, mass, motion.direction * motion.speed * dt);
        }).Schedule(inputDeps);

        return myJob;
    }
}
