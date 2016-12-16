#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct user User;
typedef struct project Project;
typedef struct file File;
struct project
{
	char* project_name;
	User** List_Of_Contributors;
	File* List_Of_Sources;
	int num_of_Contributors;
	int num_of_files;
};
struct user
{
	char* username;
	char* password;
	char* List_Of_Projects[20];
	int num_of_current_projects;
};

struct file
{
	char* File_Name;
	Project* Project;
	User* owner;
};


/*void new_project(char* project_names, char** projects, int rank);
char* findusername(char* input);
char* findpassword(char* input);
char* findinstruction(char* input);
char* findprojectname(char* input);
char* getinputasSTRING(void);
void SignUp(char*** usernames, char*** passwords, char* username, char* password, int* rank);
int finduser(char** usernames, char** passwords, char*username, char*password, int*rank);
bool findstring(char* string, char* substring);
void projects_status(char**projects, int rank);
bool findusernames(int * signuprank, char* username, char*** usernames);
int findspaces(char* input);
void checkinstructions(char*** usernames, char*** passwords, char** projects, char* input, int* state, int* signuprank, int* rank);
*/
/*In this part i add project to previous projects.*/
void new_project(char* project_names, User* users, int rank,Project* projects,int project_r) {

	/*In this part i declar variables.*/
	
	int len_Project_name = strlen(project_names);
	int project_rank;
	int len_username = strlen((users[rank]).username);
	char** p1;
	project_rank = (users[rank]).num_of_current_projects;
	projects[project_r].project_name = (char*)malloc(sizeof(char)*(len_Project_name + 1));
	strcpy(projects[project_r].project_name, project_names);
	(projects[project_r].project_name)[len_Project_name] = '\0';
	projects[project_r].List_Of_Contributors = (User**)malloc(sizeof(User) * 2);
	(projects[project_r].List_Of_Contributors[0]) = &(users[rank]);
	projects[project_r].List_Of_Sources = (File*)malloc(sizeof(File) * 2);
	projects[project_r].num_of_files = 0;
	(projects[project_r].num_of_Contributors)=1;
	(((users[rank]).List_Of_Projects)[project_rank]) = (char*)malloc(sizeof(char)*(len_Project_name + 1));
	strcpy((((users[rank]).List_Of_Projects)[project_rank]), project_names);
	(((users[rank]).List_Of_Projects)[project_rank])[len_Project_name] = '\0';
	((users[rank]).num_of_current_projects)++;
	
}

/*In this part i find name that you can see after space and store it in username.*/
char* findusername(char* input) {

	/*In this part i declar variables*/
	char* username;
	const char *p1;
	const char *p2;
	int len = 0;

	/*In this part i find instruction and username*/
	if ((p1 = strstr(input, " ") + 1) == NULL) {
		printf("Error : Finding instruction has been failed.\n");
	}
	if ((p2 = strstr(p1, " ")) == NULL) {
		printf("Error : Finding username has been failed.\n");
	}
	len = p2 - p1;

	/*In this part i allocate memory for username.*/
	if ((username = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		printf("Error : Allocation memory for username has been failed.\n");
	}

	/*In this part i copy parameter to username.*/
	strncpy(username, p1, len);
	username[len] = '\0';
	return username;
	free(username);
}

/*In this part i find password and third parameter. */
char* findpassword(char* input) {

	/*In this part i declare variables.*/
	char* password;
	const char *p1;
	const char *p2;
	int len = 0;

	/*In this part i allocate memory for username.*/
	if ((p1 = strstr(input, " ") + 1) == NULL) {
		printf("Error : Finding instruction has been failed.\n");
	}
	if ((p2 = strstr(p1, " ") + 1) == NULL) {
		printf("Error : Finding username has been failed.\n");
	}

	/*In this part i allocate memory for passsword.*/
	len = input + strlen(input) - p2;
	if ((password = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		printf("Error : Allocation memory for password has been failed.\n");
	}

	/*In this part i copy parameter to password.*/
	strncpy(password, p2, len);
	password[len] = '\0';
	return password;
	free(password);
}

/*In this function i find instruction.*/
char* findinstruction(char* input) {

	/*In this part i declare variables.*/
	char* instruction = " ";
	int i = 0;
	int model = 0;
	int len = strlen(input);
	const char *p1;

	/*In this part i count spaces as model.*/
	for (i;i < len;i++) {
		if (input[i] == ' ')
			model++;
	}

	/*In this part i allocate memory for instruction and find instruction in differante cases. */
	if (model > 2) {
		printf("error!\n");
		return NULL;
	}

	if (model == 2) {
		p1 = strstr(input, " ");
		len = p1 - input;
		if ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			printf("Error : Finding instruction has been failed.\n");
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}

	if (model == 1) {
		p1 = strstr(input, " ");
		len = p1 - input;
		if ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			printf("Error : Finding instruction has been failed.\n");
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}

	if (model == 0) {
		len = strlen(input);
		if ((instruction = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
			printf("Error : Finding instruction has been failed.\n");
		}
		strncpy(instruction, input, len);
		instruction[len] = '\0';
	}

	return instruction;
	free(instruction);
}

/*In this function i find project's name.*/
char* findprojectname(char* input) {

	/*In this part i declare variabls.*/
	char* project;
	const char *p1;
	int len;

	/*In this part i find project's name.*/
	if ((p1 = strstr(input, " ") + 1) == NULL) {
		printf("Error : Finding instruction has been failed.\n");
	}
	len = input + strlen(input) - p1;

	/*In this part i allocate memory for project's name.*/
	if ((project = (char*)malloc(sizeof(char)*(len + 1))) == NULL) {
		printf("Error : Allocation memory for project's name has been failed.\n");
	}

	/*In this part i copy second input parameter to project's name.*/
	strncpy(project, p1, len);
	project[len] = '\0';
	return project;
	free(project);
}

/*In this function i get input via getchar and save it in a string.*/
char* getinputasSTRING() {

	/*in this part i declare variabels.*/
	int firstsize = 20;
	char* input;
	input = (char*)malloc(sizeof(char)*firstsize);
	int i = 0;
	char letter = '\0';

	/*In this part i get user input char by char.*/
	while ((letter = getchar()) != '\n')
	{
		input[i++] = letter;
		if (i == firstsize) {
			input = (char*)realloc(input, sizeof(char)*(firstsize += 20));
		}
	}
	input[i++] = '\0';

	return input;
	free(input);
}

/*in this function i replace multiple spaces with single space.*/
void Replace_Multiple_Space_With_Single(char* input) {

	/*In this part i declare variabels.*/
	int SizeOfString = 0;
	int j = 0;
	int i = 0;
	SizeOfString = strlen(input);
	for (j = 0; j < SizeOfString; j++)
	{
		for (i = 0; i < SizeOfString; i++)
		{
			if (input[i] == ' ' && input[i + 1] == ' ') {
				for (int j = i; j < SizeOfString; j++)
				{
					input[j] = input[j + 1];
				}
			}
		}
	}
}

/*In this function i save user username and password and save informations about users.*/
void SignUp(User* users, char* username, char* password, int* rank) {

	/*In this part i declare variabels.*/
	char** p1 = NULL;
	char** p2 = NULL;
	int len_username = strlen(username);
	int len_password = strlen(password);
	int first_size = *rank;
	int i = 0;

	/*In this part i allocate memory for username and password.In same time i copy username and password to usernames array and password array.*/
	(users[*rank]).username = (char*)malloc(sizeof(char)*(len_username + 1));
	(users[*rank]).password = (char*)malloc(sizeof(char)*(len_password + 1));
	strcpy((users[*rank]).username, username);
	strcpy((users[*rank]).password, password);
	((users[*rank]).password)[len_password] = '\0';
	((users[*rank]).username)[len_username] = '\0';
	(users[*rank]).num_of_current_projects = 0;
	
	(*rank) = (*rank) + 1;
	
}

/*In this function itry find user username and password in users information. if i can't find user information i return (-1)*/
int finduser(User* users, char*username, char*password, int*rank) {

	/*In this part i declare variabels.*/
	int i = 0;
	int result = 0;
	bool find = false;

	/*In this part i find user information.if i find user i return user rank.*/
	for (i = 0; i < *rank; i++)
	{
		if (!strcmp((users[i].username), username))
		{
			if (!strcmp((users[i]).password, password)) {
				find = true;
				result = i;
			}
			else
			{
				result = -1;
			}
		}
	}
	if (find == false)
	{
		result = -1;
	}
	return result;
}

/*In this function i search about a string.if i find that i return true.*/
bool find_in_user_projects(User* users , char* input_projectname,int rank) {
	int i = 0;
	bool find = false;
	if ((users[rank]).num_of_current_projects != 0) {
		for (i = 0; i < (users[rank]).num_of_current_projects; i++)
		{
			if (strcmp(((users[rank]).List_Of_Projects)[i], input_projectname) == 0) {
				find = true;
				break;
			}

		}
	}
	return find;
}

/*In this part i write login user's projects on screen.*/
void projects_status(User* users, int rank) {
	int i = 0;
	int current_projects = (users[rank]).num_of_current_projects;
	for ( i = 0; i < current_projects; i++)
	{
		printf("Your projects :%s\n", ((users[rank].List_Of_Projects)[i]));
	}
}

/*In this function i count spaces in a string.*/
int findspaces(char* input) {

	/*In this part i declare variabels.*/
	int spaces = 0;
	int len = strlen(input);

	for (int i = 0; i < len; i++)
	{
		if (input[i] == ' ') {
			spaces++;
		}
	}

	return spaces;
}

/*In this part i search user's username in usernames.*/
bool findusernames(int * signuprank, char* username, User* users) {

	/*In this part i declare variabels.*/
	int i = 0;
	bool find = false;

	if (*signuprank != 0) {
		for (i = 0; i < *signuprank; i++)
		{
			if (strcmp((users[i]).username, username) == 0) {
				find = true;
				break;
			}
		}

	}

	return find;
}
bool find_projectID(int *ID, int numofprojects, Project* projects, char* name) {
	int i = 0;
	bool find_user = false;

	for (i = 0; i < numofprojects ; i++)
	{
		if (strcmp(name, (projects[i]).project_name) == 0) {
			find_user = true;
			*ID = i;
			break;
		}
	}

	return find_user;
}
/*In this function i find a user and i return user rank as userID.*/
bool finduserID(int* ID, int* signuprank, User* users, char* username) {

	/*In this part i declare variabels.*/
	int i = 0;
	bool find_user = false;

	for (i = 0; i < *signuprank; i++)
	{
		if (strcmp(username, (users[i]).username) == 0) {
			find_user = true;
			*ID = i;
			break;
		}
	}

	return find_user;
}
bool find_file_in_files(Project project, char* file_name) {
	int i = 0;
	bool find = false;
	if (project.num_of_files != 0) {
		for (i = 0; i < project.num_of_files; i++)
		{
			if (strcmp(((project.List_Of_Sources)[i]).File_Name, file_name) == 0) {
				find = true;
				break;
			}
		}
	}
	return find;
}
void add_file(Project* project, char* filename,User* owner ) {
	int size = strlen(filename);
	(*project).List_Of_Sources = (File*)realloc((*project).List_Of_Sources, sizeof(File)*(((*project).num_of_files) + 1));
	((*project).List_Of_Sources[((*project).num_of_files)]).File_Name = (char*)malloc(sizeof(size + 1));
	strcpy(((*project).List_Of_Sources[((*project).num_of_files)]).File_Name, filename);
	(((*project).List_Of_Sources)[(*project).num_of_files]).owner = owner;
	(((*project).List_Of_Sources)[(*project).num_of_files]).Project = project;
	((*project).num_of_files)++;
}
void files_status(Project TargetProject,int numOffiles) {
	int i = 0;
	printf("project %s files' names:\n", TargetProject.project_name);
	for ( i = 0; i < numOffiles; i++)
	{
		printf("%s\n", (TargetProject.List_Of_Sources[i]).File_Name);
	}
}
void add_user(char* project_names,User* users,int rank,Project* projects,int project_r) {
	int i = 0, proID = 0;
	int len_Project_name = strlen(project_names);
	int project_rank;
	int len_password = 0;
	int len_username = strlen((users[rank]).username);
	char** p1;
	find_projectID(&proID, project_r, projects, project_names);
	projects[proID].List_Of_Contributors = (User**)realloc(projects[proID].List_Of_Contributors, sizeof(User*)*(projects[proID].num_of_Contributors + 1));
	projects[proID].List_Of_Contributors[projects[proID].num_of_Contributors] = &(users[rank]);
	(projects[proID].num_of_Contributors)++;
	project_rank = (users[rank]).num_of_current_projects;
	(((users[rank]).List_Of_Projects)[project_rank]) = (char*)malloc(sizeof(char)*(len_Project_name + 1));
	strcpy((((users[rank]).List_Of_Projects)[project_rank]), project_names);
	(((users[rank]).List_Of_Projects)[project_rank])[len_Project_name] = '\0';

	((users[rank]).num_of_current_projects)++;
}

/*in this function i check user input i find user instructions , parameters and misstakes.i use this information and do the best work.*/
void checkinstructions(User* users, char* input, int* state, int* signuprank, int* rank,int* project_r,Project* projects) {

	/*In this part i declare variabels.*/
	char* instruction = NULL;
	char* username = NULL;
	char* password = NULL;
	char* project = NULL;
	int spaces = 0;
	bool find = false;
	bool correct_instruction = false;
	bool find_user = false;
	int userID = 0;
	int projectID = 0;

	/*In this part i get user instruction.*/
	instruction = findinstruction(input);

	/*In this part i have some conditions about user instruction.in each condition i check parameters and do the best work.*/
	if (instruction == NULL) {
		printf("error! your instruction is not correct!\n");
		return;
	}

	/*In this part you can see signup instruction's conditions.*/
	if ((strcmp(instruction, "signup") == 0) && (*state == 0))
	{
		spaces = findspaces(input);
		if (spaces == 2) {
			username = findusername(input);
			password = findpassword(input);
			find = findusernames(signuprank, username, users);
			if (find == false && strcmp(username, "") != 0 && strcmp(password, "") != 0 && strcmp(username, " ") != 0 && strcmp(password, " ") != 0) {
				SignUp(users, username, password, signuprank);
				*state = 1;
				*rank = (*signuprank) - 1;
				printf("User %s is added to users.\n", username);
			}
			else if (strcmp(username, "") == 0 || strcmp(password, "") == 0 || strcmp(username, " ") == 0 || strcmp(password, " ") == 0) {
				printf("Your instruction is not correct!\nsignup <username> <password>\n");
				return;
			}

			else
			{
				printf("I find this username !Please try again!\n ");
				return;
			}
			correct_instruction = true;
		}
		else
		{
			printf("error! your instruction is not correct!\nsignup <username> <password>\n");
			return;
		}


	}

	/*In this part you can see login instruction's conditions.*/
	if ((strcmp(instruction, "login") == 0) && (*state != 1) && (*state != 2))
	{
		spaces = findspaces(input);
		if (spaces == 2)
		{
			username = findusername(input);
			password = findpassword(input);
			if ((*rank = finduser(users, username, password, signuprank)) != -1 && strcmp(username, "") != 0 && strcmp(password, "") != 0 && strcmp(username, " ") != 0 && strcmp(password, " ") != 0) {

				printf("Welcome back dear %s!\n", username);
				*state = 2;
				correct_instruction = true;
			}
			else if (strcmp(username, "") == 0 || strcmp(password, "") == 0 || strcmp(username, " ") == 0 || strcmp(password, " ") == 0) {
				printf("your instruction is not correct!\nlogin <username> <password>\n");
				return;
			}
			else
			{
				printf("error! your username or password  not found!\nlogin <username> <password>\n");
				return;
			}
		}

		else
		{
			printf("error! your instruction is not correct!\nlogin <username> <password>\n");
			return;
		}
	}

	/*In this part you can see new_project instruction's conditions.*/
	if ((strcmp(instruction, "new_project") == 0) && (*state == 2 || *state == 1))
	{
		spaces = findspaces(input);
		if (spaces == 1) {
			project = findprojectname(input);
			if (find_in_user_projects(users, project,*rank) == false && strcmp(project, "") != 0 && strcmp(project, " ") != 0) {
				new_project(project, users, *rank,projects,*project_r);
				*project_r = *project_r + 1;
				printf("New project %s is added for user %s\n", project, (users[*rank]).username);
			}
			else if (strcmp(project, "") == 0 || strcmp(project, " ") == 0)
			{
				printf("your instruction is not correct!\nnew_project <project's name>\n");
			}
			else
			{
				printf("I find this project in your projects!\n");
				return;
			}
		}
		else
		{
			printf("your instruction is not correct!\nnew_project <project's name>\n");
			return;
		}
		correct_instruction = true;
	}

	/*In this part you can see add_user instruction's conditions.*/
	if ((strcmp(instruction, "add_user") == 0) && (*state == 2 || *state == 1))
	{

		spaces = findspaces(input);
		if (spaces == 2) {
			username = findusername(input);
			project = findpassword(input);
			find_user = finduserID(&userID,signuprank,users,username);
			if (find_user == true && strcmp(username, " ") != 0 && strcmp(project, " ") != 0 && strcmp(project, "") != 0 && strcmp(username, "") != 0) {
				if (find_in_user_projects(users, project,userID) == false && find_in_user_projects(users,project,*rank) == true && strcmp((users[*rank]).username, username) != 0) {
					add_user(project,users,userID,projects,*project_r);
					printf("New contributer \"%s\" is added to project \"%s\" now!\n", username, project);
				}
				else if (strcmp((users[*rank]).username, username) == 0)
				{
					printf("You can use \"add_user\" for add users to your projects but you can not use it for add yourself!\n");
				}
				else if (find_in_user_projects(users,project,*rank) == false) {
					printf("You can not use \"add_user\".I can not find this project in your projects!\n");
					return;
				}
				else if (strcmp(username, " ") == 0 || strcmp(project, " ") == 0 || strcmp(project, "") == 0 || strcmp(username, "") == 0) {
					printf("your instruction is not correct!\nadd_user <username> <project's name>\n");
					return;
				}
				else
				{
					printf("I find %s project in %s's projects!\n", project, (users[userID]).username);
					return;
				}
			}
			else
			{
				printf("User not found!\nadd_user <username> <project's name>\n");
				return;
			}
		}
		else
		{
			printf("Your instruction is not correct!\nadd_user <username> <project's name>\n");
			return;
		}
		correct_instruction = true;
	}
	
	/*In this part you can see projects_status instruction's conditions.*/
	if ((strcmp(instruction, "projects_status") == 0) && (*state == 2 || *state == 1))
	{
		int len = strlen(input);
		int len_instruction = strlen(instruction);
		if (len == len_instruction) {
			projects_status(users, *rank);
			correct_instruction = true;
		}
	}
	if ((strcmp(instruction, "files_status") == 0) && (*state == 2 || *state == 1))
	{
		spaces = findspaces(input);
		if (spaces == 1) {
			project = findprojectname(input);
			find_projectID(&projectID, *project_r, projects, project);
			if (find_in_user_projects(users, project, *rank) == true && strcmp(project, "") != 0 && strcmp(project, " ") != 0) {
				files_status(projects[projectID], projects[projectID].num_of_files);
			}
			else if (strcmp(project, "") == 0 || strcmp(project, " ") == 0)
			{
				printf("your instruction is not correct!\nfiles_status <project's name>\n");
			}
			else
			{
				printf("I can not find this project in your projects!\n");
				return;
			}
		}
		else
		{
			printf("your instruction is not correct!\nfiles_status <project's name>\n");
			return;
		}
		correct_instruction = true;
	}
	if ((strcmp(instruction, "add_file") == 0) && (*state == 2 || *state == 1))
	{

		spaces = findspaces(input);
		if (spaces == 2) {
			username = findusername(input);
			project = findpassword(input);
			find_projectID(&projectID, *project_r, projects, project);
			if ( strcmp(username, " ") != 0 && strcmp(project, " ") != 0 && strcmp(project, "") != 0 && strcmp(username, "") != 0) {
				
				if ( find_in_user_projects(users, project, *rank) == true && find_file_in_files(projects[projectID],username)==false) {
					add_file(&(projects[projectID]),username,&(users[*rank]) );
					printf("New file \"%s\" is added to project \"%s\" now!\n", username, project);
				}
				else if (strcmp((users[*rank]).username, username) == 0)
				{
					printf("You can use \"add_user\" for add users to your projects but you can not use it for add yourself!\n");
				}
				else if (find_in_user_projects(users, project, *rank) == false) {
					printf("You can not use \"add_user\".I can not find this project in your projects!\n");
					return;
				}
				else if (strcmp(username, " ") == 0 || strcmp(project, " ") == 0 || strcmp(project, "") == 0 || strcmp(username, "") == 0) {
					printf("your instruction is not correct!\nadd_user <username> <project's name>\n");
					return;
				}
				else
				{
					printf("I find %s project in %s's projects!\n", project, (users[userID]).username);
					return;
				}
			}
			else
			{
				printf("User not found!\nadd_user <username> <project's name>\n");
				return;
			}
		}
		else
		{
			printf("Your instruction is not correct!\nadd_user <username> <project's name>\n");
			return;
		}
		correct_instruction = true;
	}
	
	/*In this part you can see logout instruction's conditions.*/
	if ((strcmp(instruction, "logout") == 0) && (*state == 1 || *state == 2))
	{
		int len = strlen(input);
		int len_instruction = strlen(instruction);
		if (len == len_instruction) {
			printf("You signed out successfully. See you soon!\n");
			correct_instruction = true;
			*state = 0;
		}
	}
	if (correct_instruction == false)
		printf("error! your instruction is not correct!\n");
	free(instruction);
	free(username);
	free(password);
	free(project);
}

/*In this function i reallocate usernames , passwords and projects.*/
void MemoryAllocation(char*** usernames, char*** passwords, char*** projects, int rank) {

	/*In this part i declare variables. some of them are pointers.*/
	int first_size = 0;
	int firstsize = 0;
	int size_p1 = 0;
	int size_p2 = 0;
	int size_p3 = 0;
	int size = 0;
	char*** p1;
	char*** p2;
	char*** p3;

	/*this condition is used when i have two empety room . */
	if ((rank % 7) == 0) {

		/*In this part i initialize variables.*/
		first_size = rank;
		p1 = (char***)malloc(sizeof(char**) * 2);
		p2 = (char***)malloc(sizeof(char**) * 2);
		p3 = (char***)malloc(sizeof(char**) * 2);
		firstsize = rank + 3;
		p1[0] = (char**)malloc(sizeof(char*) * firstsize);
		p2[0] = (char**)malloc(sizeof(char*) * firstsize);
		p3[0] = (char**)malloc(sizeof(char*) * firstsize);

		/*In this part i copy usernames to p1.*/
		for (int i = 0; i < firstsize; i++)
		{
			size = strlen(usernames[0][i]);
			p1[0][i] = (char*)malloc(sizeof(char)*(size + 1));
			strcpy(p1[0][i], usernames[0][i]);
		}

		/*In this part i copy passwords to p2.*/
		for (int i = 0; i < firstsize; i++)
		{
			size = strlen(passwords[0][i]);
			p2[0][i] = (char*)malloc(sizeof(char)*(size + 1));
			strcpy(p2[0][i], passwords[0][i]);
		}

		/*In this part i copy projects to p3.*/
		for (int i = 0; i < firstsize; i++)
		{
			size = strlen(projects[0][i]);
			p3[0][i] = (char*)malloc(sizeof(char)*(size + 1));
			strcpy(p3[0][i], projects[0][i]);
		}

		/*In this part i free allocated memory.*/
		first_size += 10;
		free(usernames[0]);
		free(passwords[0]);
		free(projects[0]);

		/*In this part i allocate memory usernames,passwords and projects.*/
		usernames[0] = (char**)malloc(sizeof(char*)*(first_size));
		passwords[0] = (char**)malloc(sizeof(char*)*(first_size));
		projects[0] = (char**)malloc(sizeof(char*)*(first_size));

		for (int i = 0; i < first_size; i++)
		{

			/*In this part i copy usernames that you can find in p1 to usernames array.
			and i copy passwords that you can find in p2 to passwords array.
			and i copy projects that you can find in p3 to projects array.*/
			if (i <= (firstsize - 1)) {
				size_p1 = strlen(p1[0][i]);
				size_p2 = strlen(p2[0][i]);
				size_p3 = strlen(p3[0][i]);
				usernames[0][i] = (char*)malloc(sizeof(char)*(size_p1 + 1));
				passwords[0][i] = (char*)malloc(sizeof(char)*(size_p2 + 1));
				projects[0][i] = (char*)malloc(sizeof(char)*(size_p3 + 1));
				strcpy(usernames[0][i], p1[0][i]);
				strcpy(passwords[0][i], p2[0][i]);
				strcpy(projects[0][i], p3[0][i]);
				usernames[0][i][size_p1] = '\0';
				passwords[0][i][size_p2] = '\0';
				projects[0][i][size_p3] = '\0';
			}

			/*In this part i fill usernames and passwords and projects arrays. */
			else
			{
				usernames[0][i] = (char*)malloc(sizeof(char) * 3);
				passwords[0][i] = (char*)malloc(sizeof(char) * 3);
				projects[0][i] = (char*)malloc(sizeof(char) * 3);
				strcpy(usernames[0][i], "");
				strcpy(passwords[0][i], "");
				strcpy(projects[0][i], "");
				usernames[0][i][1] = '\0';
				passwords[0][i][1] = '\0';
				projects[0][i][1] = '\0';
			}
		}

		/*In this part i free allocated memory.*/
		free(p1);
		free(p2);
		free(p3);
	}
}

int main() {

	/*In this part i declar some variables. some of them are pointers.*/
	User* users;
	Project* projects;
	char* input;
	int state = 0;
	int signuprank = 0;
	int rank = 0;
	int i = 0;
	int project_r = 0;
	if ((users = (User*)malloc(sizeof(User) * 10)) == NULL) {
		printf("Error : Allocation memory for usernames has been failed!\n");
		free(users);
	}
	if ((projects = (Project*)malloc(sizeof(Project) * 10)) == NULL) {
		printf("Error : Allocation memory for usernames has been failed!\n");
		free(projects);
	}
	for ( i = 0; i < 10; i++)
	{
		
	}
	/*In this part i allocate memory for usernames with char*** type*/
	/*if ((usernames = (char***)malloc(sizeof(char**) * 2)) == NULL) {
		printf("Error : Allocation memory for usernames has been failed!\n");
		free(usernames);
	}

	/*In this part i allocate memory for passwords with char*** type*/
	/*if ((passwords = (char***)malloc(sizeof(char**) * 2)) == NULL) {
		printf("Error : Allocation memory for passwords has been failed!\n");
		free(passwords);
	}

	/*In this part i allocate memory for projects' names with char*** type and i use projects array for storing projects names.*/
	/*if ((projects = (char***)malloc(sizeof(char**) * 2)) == NULL) {
		printf("Error : Allocation memory for projects has been failed!\n");
		free(passwords);
	}

	/*In this part i allocate memory for input with char** type. input consists of instruction and other parameters.*/
	/*if ((input = (char*)malloc(sizeof(char) * 10)) == NULL) {
		printf("Error : Allocation memory for input has been failed!\n");
		free(input);
	}

	/*In this part i allocate memory for usernames[0] with char** type*/
	/*if ((usernames[0] = (char**)malloc(sizeof(char*) * 10)) == NULL) {
		printf("Error : Allocation memory for usernames has been failed!\n");
		free(usernames[0]);
	}

	/*In this part i allocate memory for passwords[0] with char** type*/
	/*if ((passwords[0] = (char**)malloc(sizeof(char*) * 10)) == NULL) {
		printf("Error : Allocation memory for passwords has been failed!\n");
		free(passwords[0]);
	}

	/*In this part i allocate memory for projects[0] with char** type*/
	/*if ((projects[0] = (char**)malloc(sizeof(char*) * 10)) == NULL) {
		printf("Error : Allocation memory for projects has been failed!\n");
		free(projects);
	}
	*/
	/*In this part i initialize projects , usernames and passwords arrays. */
	/*for (int i = 0; i < 10; i++)
	{
		projects[0][i] = " ";
	}
	for (int i = 0; i < 10; i++)
	{
		usernames[0][i] = " ";
	}
	for (int i = 0; i < 10; i++)
	{
		passwords[0][i] = " ";
	}
	*/
	/*This part is main part and all of actions is here.In this part i use functions to get input and to check input .
	in addition i use MemoryAllocation function to allocate memory when user want to have more memory size.*/
	while (true)
	{
		input = getinputasSTRING();
		checkinstructions(users, input, &state, &signuprank, &rank,&project_r,projects);
		if (signuprank % 7 == 0&&signuprank!=0) {
			int size = signuprank;
			size += 10;
			User* u = (User*)realloc(users, sizeof(User) *size);
			if (u != NULL) {
				users = u;
			}
		}
		if (project_r % 7 == 0&&project_r!=0) {
			int size = project_r;
			size += 10;
			Project* u = (Project*)realloc(projects, sizeof(Project) *size);
			if (u != NULL) {
				projects = u;
			}
		}
	}


	return 0;
}