#include <stdio.h>
#include <math.h>

int main() {

    printf("\n===== COSMIC SWEEPERS : COLLISION ANALYSIS REPORT =====\n");

    float sx, sy, sz;
    // Satellite position
    printf("Enter the satellite position (x y z): ");
    scanf("%f %f %f", &sx, &sy, &sz);

    float dx, dy, dz;
    // Debris position
    printf("Enter the debris position (x y z): ");
    scanf("%f %f %f", &dx, &dy, &dz);

    float ss, sd;
    // Speeds
    printf("Enter the satellite speed: ");
    scanf("%f", &ss);

    printf("Enter the debris speed: ");
    scanf("%f", &sd);

    // Distance calculation
    float distance = sqrt(
        pow(dx - sx, 2) +
        pow(dy - sy, 2) +
        pow(dz - sz, 2)
    );

    float safe_distance = 5.0;   // Safety threshold
    float relative_speed = fabs(ss - sd);

    // Time to closest approach (simple estimate)
    float time_to_closest = distance / (relative_speed + 0.001);

    // Collision probability (heuristic)
    float collision_probability = (safe_distance - distance) / safe_distance * 100;
    if (collision_probability < 0) collision_probability = 0;

    printf("\nDistance to debris: %.2f units\n", distance);
    printf("Relative speed: %.2f units/s\n", relative_speed);
    printf("Estimated time to closest approach: %.2f seconds\n", time_to_closest);
    printf("Estimated collision probability: %.1f%%\n", collision_probability);

    printf("System Mode: Autonomous Decision Support Enabled\n");

    // -------- CASE 1: Same direction, similar speed --------
    if (distance < safe_distance && relative_speed < 0.5) {

        printf("\nCASE 1: Same direction, similar speed\n");
        printf("Risk Level: LOW\n");
        printf("Action: Slight speed adjustment recommended\n");
        printf("Explanation: Minor corrections create long-term safe separation\n");

    }

    // -------- CASE 2: Crossing orbits --------
    else if (distance < safe_distance && relative_speed >= 0.5 && relative_speed < (ss + sd)) {

        printf("\nCASE 2: Crossing orbital paths\n");
        printf("Risk Level: MEDIUM\n");
        printf("Action: Temporary altitude adjustment recommended\n");
        printf("Explanation: Small altitude change avoids orbital intersection\n");

    }

    // -------- CASE 3: Opposite direction (head-on) --------
    else if (distance < safe_distance && relative_speed >= (ss + sd) - 0.5) {

        printf("\nCASE 3: Opposite direction motion\n");
        printf("Risk Level: HIGH\n");
        printf("Action: Immediate evasive maneuver required\n");
        printf("Explanation: High-speed head-on collision could be catastrophic\n");
        printf("Command: Auto-evasion sequence initiated\n");

    }

    // -------- SAFE CASE --------
    else {

        printf("\nSTATUS: SAFE ZONE\n");
        printf("No collision risk detected\n");

    }

    printf("\nLOG: Tracking event stored for mission analysis\n");
    printf("===== END OF REPORT =====\n");

    return 0;
}
