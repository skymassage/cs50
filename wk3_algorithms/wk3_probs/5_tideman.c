// https://cs50.harvard.edu/x/2023/psets/3/tideman/
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
bool check_cycle(int start, int end);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            for (int j = 0; j < rank - 1; j++) // Checks if two candidates have the same name.
            {
                if (ranks[rank] == ranks[j])
                    return false;
            }
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])  // Because i is the winner and i is the loser, preferences[i][j] must be large than preferences[j][i].
            {
                pair temp = {i, j};
                pairs[pair_count] = temp;
                pair_count++;
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory (Here I use bubble sort)
void sort_pairs(void)
{
    // TODO
    for (int i = 0; i < (pair_count - 1); i++)
    {
        for (int j = 0; j < (pair_count - i - 1); j++)
        {
            if (preferences[pairs[j].winner][pairs[j].loser] < preferences[pairs[j+1].winner][pairs[j+1].loser]) // This is same as the inequality of the difference between pairs[j] and pairs[j+1].
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j+1];
                pairs[j+1] = temp;
            }
        }
    }

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!check_cycle(pairs[i].winner, pairs[i].loser))  // Check if there is a path containing winners and losers can form a cycle.
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

bool check_cycle(int start, int end)
{
    // Return True if there is a cycle created (recursion base case)
    if (end == start)
        return true;

    // Loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[end][i] && check_cycle(start, i))
            return true;
    }

    return false;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    // If each element in the column of "locked" is false, the corrosponding candidate is the source, i.e. the winner.
    for (int i = 0; i < candidate_count; i++)
    {
        int source_count = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i] == false)
                source_count++;
        }

        if (source_count == candidate_count)
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }

    // Other method:
    /*for (int i = 0; i < candidate_count; i++)
    {
        bool if_loser = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                if_loser = true;
                break;
            }
        }

        if (!if_loser)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }*/

    return;
}