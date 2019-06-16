using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BoardController : MonoBehaviour
{
    public float rotationMaxX;
    public float rotationMaxZ;
    public float sensivity;
    public float returnSpeed;

    void FixedUpdate()
    {
        float inputX = Input.GetAxis("Horizontal") * sensivity;
        float inputY = Input.GetAxis("Vertical") * sensivity;

        if ((inputX != 0) || (inputY != 0))
        {
            transform.Rotate(-inputY, 0.0f, inputX);

            transform.rotation = new Quaternion(
                Mathf.Clamp(transform.rotation.x, -rotationMaxX, rotationMaxX),
                transform.rotation.y,
                Mathf.Clamp(transform.rotation.z, -rotationMaxZ, rotationMaxZ),
                transform.rotation.w);
        }

        else
        {
            transform.rotation = Quaternion.Lerp(transform.rotation, Quaternion.identity, returnSpeed * Time.deltaTime);
        }
        
    }
}