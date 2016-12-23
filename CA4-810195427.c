 #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int bool;
#define false 0
#define true 1

typedef struct user User;
typedef struct project Project;
typedef struct file File;
/*in this part i define project , file & user structurs.*/
/*i save users projects name in a array and create project structs fot storing projects information.*/
struct project
{
	char* project_name;
	User** List_Of_Contributors;
	int* index_of_contributors;
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
	int ownerID;
	int projectID;
};



/*In this part i add project to previous projects.*/
void new_project(char* project_names, User* users, int rank, Project* projects, int project_r) {

	/*In this part i declar variables.*/

	int len_Project_name = strlen(project_names);
	int project_rank;
	int len_username = strlen((users[rank]).username);
	
	project_rank = (users[rank]).num_of_current_projects;
	projects[project_r].project_name = (char*)malloc(sizeof(char)*(len_Project_name + 1));
	strcpy(projects[project_r].project_name, project_names);
	(projects[project_r].project_name)[len_Project_name] = '\0';
	projects[project_r].List_Of_Contributors = (User**)malloc(sizeof(User) * 2);
	projects[project_r].index_of_contributors = (int*)malloc(sizeof(int) * 2);
	(projects[project_r].List_Of_Contributors[0]) = &(users[rank]);
	(projects[project_r].index_of_contributors[0])=rank;
	projects[project_r].List_Of_Sources = (File*)malloc(sizeof(File) * 2);
	projects[project_r].num_of_files = 0;
	(projects[project_r].num_of_Contributors) = 1;
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
	int i = 0;
	char letter = '\0';
	input = (char*)malloc(sizeof(char)*firstsize);
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

/*In this function i try find user username and password in users information. if i can't find user information i return (-1)*/
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

/*In this function i search about a string.if i find that i return true.this string is a projectname.*/
bool find_in_user_projects(User* users, char* input_projectname, int rank) {
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
	printf("Your projecs' name :\n");
	if(current_projects==0){
		printf("There is not any project in your projects.\n");
	}
	for (i = 0; i < current_projects; i++)
	{
		printf("\t%d) %s\n",i+1, ((users[rank].List_Of_Projects)[i]));
	}
}

/*In this function i count spaces in a string.*/
int findspaces(char* input) {

	/*In this part i declare variabels.*/
	int spaces = 0;
	int len = strlen(input);
	int i=0;
	for ( i = 0; i < len; i++)
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
/*in this function i serch a project in projects.if i find my target i return true.*/
bool find_projectID(int *ID, int numofprojects, Project* projects, char* name) {
	int i = 0;
	bool find_user = false;

	for (i = 0; i < numofprojects; i++)
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
/*i search a file in a project files. if i find that i return true.*/
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
/*in add file i add a file to a project files.you know a project has files and user can add files to projects.*/
void add_file(Project* project, char* filename, User* owner,int userID,int projectID) {
	int size = strlen(filename);
	(*project).List_Of_Sources = (File*)realloc((*project).List_Of_Sources, sizeof(File)*(((*project).num_of_files) + 1));
	((*project).List_Of_Sources[((*project).num_of_files)]).File_Name = (char*)malloc(sizeof(size + 1));
	strcpy(((*project).List_Of_Sources[((*project).num_of_files)]).File_Name, filename);
	(((*project).List_Of_Sources)[(*project).num_of_files]).owner = owner;
	(((*project).List_Of_Sources)[(*project).num_of_files]).Project = project;
	(((*project).List_Of_Sources)[(*project).num_of_files]).ownerID=userID;
	(((*project).List_Of_Sources)[(*project).num_of_files]).projectID=projectID;
	((*project).num_of_files)++;
}
/*files_status show a project files.you can use it to see wich files you can find in this project.*/
void files_status(Project TargetProject, int numOffiles) {
	int i = 0;
	printf("project \"%s\" files' name:\n", TargetProject.project_name);
	if(numOffiles==0){
		printf("There is not any files in \"%s\" project.\n",TargetProject.project_name);
	}
	for (i = 0; i < numOffiles; i++)
	{
		printf("\t%d) %s\n",i+1, (TargetProject.List_Of_Sources[i]).File_Name);
	}
}
/*user can add another user to a project.for this goal i use add_user function.*/
void add_user(char* project_names, User* users, int rank, Project* projects, int project_r) {
	int i = 0, proID = 0;
	int len_Project_name = strlen(project_names);
	int project_rank;
	int len_password = 0;
	int len_username = strlen((users[rank]).username);
	
	find_projectID(&proID, project_r, projects, project_names);
	projects[proID].List_Of_Contributors = (User**)realloc(projects[proID].List_Of_Contributors, sizeof(User*)*(projects[proID].num_of_Contributors + 1));
	projects[proID].index_of_contributors = (int*)realloc(projects[proID].index_of_contributors, sizeof(int)*(projects[proID].num_of_Contributors + 1));
	projects[proID].List_Of_Contributors[projects[proID].num_of_Contributors] = &(users[rank]);
	projects[proID].index_of_contributors[projects[proID].num_of_Contributors]=rank;
	(projects[proID].num_of_Contributors)++;
	project_rank = (users[rank]).num_of_current_projects;
	(((users[rank]).List_Of_Projects)[project_rank]) = (char*)malloc(sizeof(char)*(len_Project_name + 1));
	strcpy((((users[rank]).List_Of_Projects)[project_rank]), project_names);
	(((users[rank]).List_Of_Projects)[project_rank])[len_Project_name] = '\0';

	((users[rank]).num_of_current_projects)++;
}
/*save functions can store Data in HDD.this function use projects_info file to save Data. */
void save_projects_information(Project* projects, int project_r,User* users) {
	FILE* file;
	int i=0;
	int j=0;
	file = fopen("projects_info.txt", "w");
	for (i = 0; i < project_r; i++)
	{
		fprintf(file, "%s\n", projects[i].project_name);
		for ( j = 0; j < projects[i].num_of_files; j++)
		{
			fprintf(file, "%s %s\n", (projects[i].List_Of_Sources)[j].File_Name, users[(projects[i].List_Of_Sources)[j].ownerID].username);
		}
		fprintf(file, "***\n");
	}
	fclose(file);
}
/*this function use users_info to save information about users.*/
void save_users_information(User* users, int signuprank) {
	FILE* file;
	int i=0;
	int j=0;
	file = fopen("users_info.txt", "w");
	for ( i = 0; i < signuprank; i++)
	{
		fprintf(file, "%s\n%s\n", users[i].username, users[i].password);
		for ( j = 0; j < users[i].num_of_current_projects; j++)
		{
			fprintf(file, "%s\n", (users[i].List_Of_Projects)[j]);
		}
		fprintf(file, "***\n");
	}
	fclose(file);
}
/*check get string that computer read from file and save Data in arrays.*/
void check(char* input, int line, int* project_r, int* signuprank, User* users) {
	int size = 0;
	if (line == 1) {
		size = strlen(input);
		users[*signuprank].username = (char*)malloc(sizeof(char)*(size + 1));
		strcpy(users[*signuprank].username, input);
		users[*signuprank].username[size] = '\0';

	}
	if (line == 2) {
		size = strlen(input);
		users[*signuprank].password = (char*)malloc(sizeof(char)*(size + 1));
		strcpy(users[*signuprank].password, input);
		users[*signuprank].password[size] = '\0';
	}
	if (line >= 3) {
		size = strlen(input);
		users[*signuprank].List_Of_Projects[*project_r] = (char*)malloc(sizeof(char)*(size + 1));
		strcpy(users[*signuprank].List_Of_Projects[*project_r], input);
		(users[*signuprank].List_Of_Projects[*project_r])[size] = '\0';
		(*project_r)++;
	}
}
/*this function count howmany characters you write in each line of file and count lines. */
int* counter(int* line, char* filename) {
	FILE* file;
	char c;
	int linec = 0;
	int* result;
	int i = 0;
	file = fopen(filename, "r");
	if (file) {
		while ((c = fgetc(file)) != EOF)
		{
			if (c == '\n') {
				(*line)++;
				continue;
			}
		}
		printf("%s lines :%d\n",filename, *line);
		result = (int *)malloc(sizeof(int)*(*line));
		fseek(file, 0, SEEK_SET);
		while ((c = fgetc(file)) != EOF)
		{
			if (c == '\n') {
				result[i] = linec + 1;
				linec = 0;
				i++;
				continue;
			}
			linec++;
		}
		result[i] = 4;
		fclose(file);
	}
	else
	{
		result = (int *)malloc(sizeof(int));
	}
	return result;
	free(result);
}
/*read file line by line and chek lines via check function.*/
void load_users_information(User** users, int* signuprank) {
	FILE* file;
	int line = 0;
	int* count; 
	char* lines;
	int project_r = 0;
	int state = 0;
	User* p1;
	int size = 0;
	int i=0;
	count = counter(&line, "users_info.txt");
	file = fopen("users_info.txt", "r");
	if (file&&*count != -1) {
		fseek(file, 0, SEEK_SET);
		for ( i = 0; i < line; i++)
		{
			lines = (char*)malloc(sizeof(char)*(count[i]));
			fscanf(file, "%s", lines);
			if (strcmp(lines, "***") != 0) {
				check(lines, state + 1, &project_r, signuprank, *users);
				state++;
				free(lines);
			}
			else
			{
				state = 0;
				(*users)[*signuprank].num_of_current_projects = project_r;
				(*signuprank)++;
				project_r = 0;
				free(lines);
			}
			if ((*signuprank) % 7 == 0 && (*signuprank) != 0) {
				size = *signuprank;
				size += 10;
				p1 = (User*)realloc(*users, sizeof(User)*(size));
				if (p1 != NULL) {
					*users = p1;
				}
			}
		}

		fclose(file);

	}
}
/*get string from another function and save them in projects and files structures.*/
void check_projects_file(char* input, int line, int* num_of_file, int* project_r, Project* projects, User* users, int signuprank) {
	int size = 0;
	char* filename;
	char* owner;
	int i=0;
	int j=0;
	if (line == 1)
	{
		size = strlen(input);
		projects[*project_r].project_name = (char*)malloc(sizeof(char)*(size + 1));
		strcpy(projects[*project_r].project_name, input);
		projects[*project_r].project_name[size] = '\0';
		projects[*project_r].num_of_Contributors = 0;
		projects[*project_r].num_of_files = 0;
		projects[*project_r].List_Of_Sources = (File*)malloc(sizeof(File) * ((*num_of_file) + 1));
	}
	if (line == 2) {
		filename = findinstruction(input);
		owner = findprojectname(input);
		size = strlen(filename);
		projects[*project_r].List_Of_Sources = (File*)malloc(sizeof(File) * ((*num_of_file) + 1));
		(projects[*project_r].List_Of_Sources)[*num_of_file].Project = &(projects[*project_r]);
		(projects[*project_r].List_Of_Sources)[*num_of_file].projectID=*project_r;
		(projects[*project_r].List_Of_Sources)[*num_of_file].File_Name = (char*)malloc(sizeof(char)*(size + 1));
		strcpy((projects[*project_r].List_Of_Sources)[*num_of_file].File_Name, filename);
		(projects[*project_r].List_Of_Sources)[*num_of_file].File_Name[size] = '\0';
		for ( i = 0; i < signuprank; i++)
		{
			if (strcmp(users[i].username, owner) == 0) {
				(projects[*project_r].List_Of_Sources)[*num_of_file].owner = &(users[i]);
				(projects[*project_r].List_Of_Sources)[*num_of_file].ownerID=i;
				break;
			}
		}
		
		(*num_of_file)++;
	}
	if (line >= 3) {
		filename = findinstruction(input);
		owner = findprojectname(input);
		size = strlen(filename);
		projects[*project_r].List_Of_Sources = (File*)realloc(projects[*project_r].List_Of_Sources, sizeof(File) * ((*num_of_file) + 1));
		(projects[*project_r].List_Of_Sources)[*num_of_file].Project = &(projects[*project_r]);
		(projects[*project_r].List_Of_Sources)[*num_of_file].projectID=*project_r;
		(projects[*project_r].List_Of_Sources)[*num_of_file].File_Name = (char*)malloc(sizeof(char)*(size + 1));
		strcpy((projects[*project_r].List_Of_Sources)[*num_of_file].File_Name, filename);
		(projects[*project_r].List_Of_Sources)[*num_of_file].File_Name[size] = '\0';
		for ( i = 0; i < signuprank; i++)
		{
			if (strcmp(users[i].username, owner) == 0) {
				(projects[*project_r].List_Of_Sources)[*num_of_file].owner = &(users[i]);
				(projects[*project_r].List_Of_Sources)[*num_of_file].ownerID=i;
				break;
			}
		}
		(*num_of_file)++;
	}
}
/*read projects_info file line by line and check them via check_projects_file*/
void load_projects_information(Project** projects, User* users, int*project_r, int signuprank) {
	FILE* file;
	int line = 0;
	char* lines;
	int* count ;
	int size = 0;
	int state = 0;
	int num_of_file = 0;
	char* input;
	Project* p1;
	int i=0;
	count = counter(&line, "projects_info.txt");
	file = fopen("projects_info.txt", "r");
	if (file&&*count != -1) {
		fseek(file, 0, SEEK_SET);
		for ( i = 0; i < line; i++) {
			lines=(char*)malloc(sizeof(char)*(count[i]+1));
			fgets(lines, count[i]+1, file);
			input = strtok(lines, "\n");
			if (strcmp(input, "***") != 0) {
				state++;
				check_projects_file(input, state, &num_of_file, project_r, *projects, users, signuprank);
			}
			else
			{
				int i=0,j=0;
				(*projects)[*project_r].num_of_files = num_of_file;
				(*projects)[*project_r].List_Of_Contributors=(User**)malloc(sizeof(User*)*2);
				(*projects)[*project_r].index_of_contributors=(int*)malloc(sizeof(int)*2);
				for ( i = 0; i < signuprank; i++)
				{
					for ( j = 0; j <users[i].num_of_current_projects; j++)
					{
						if (strcmp((users[i].List_Of_Projects)[j], ((*projects)[*project_r]).project_name) == 0) {
							(*projects)[*project_r].index_of_contributors=(int*)realloc((*projects)[*project_r].index_of_contributors,sizeof(int)*(2+(*projects)[*project_r].num_of_Contributors));
							(*projects)[*project_r].List_Of_Contributors = (User**)realloc((*projects)[*project_r].List_Of_Contributors, sizeof(User*) * ((*projects)[*project_r].num_of_Contributors + 1));
							((*projects)[*project_r].List_Of_Contributors)[(*projects)[*project_r].num_of_Contributors] = &(users[i]);
							((*projects)[*project_r].index_of_contributors)[(*projects)[*project_r].num_of_Contributors]=i;
							(((*projects)[*project_r]).num_of_Contributors)++;
						}
					}

				}
				(*project_r)++;
				state = 0;
				num_of_file = 0;
			}
			if ((*project_r) % 7 == 0 && (*project_r) != 0) {
				size = *project_r;
				size += 10;
				p1 = (Project*)realloc(*projects, sizeof(Project)*(size));
				if (p1 != NULL) {
					*projects = p1;
				}
			}
			free(lines);
		}
	}
}
/*in this function i check user input i find user instructions , parameters and misstakes.i use this information and do the best work.*/
void checkinstructions(User* users, char* input, int* state, int* signuprank, int* rank, int* project_r, Project* projects) {

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
	if ((strcmp(instruction, "login") == 0) && (*state != 1) && (*state != 2) && (*state == 0))
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
			if (find_in_user_projects(users, project, *rank) == false&&find_projectID(&projectID,*project_r,projects,project)==false && strcmp(project, "") != 0 && strcmp(project, " ") != 0&&users[*rank].num_of_current_projects!=20) {
				new_project(project, users, *rank, projects, *project_r);
				*project_r = *project_r + 1;
				printf("New project %s is added for user %s\n", project, (users[*rank]).username);
			}
			else if (strcmp(project, "") == 0 || strcmp(project, " ") == 0)
			{
				printf("your instruction is not correct!\nnew_project <project's name>\n");
			}
			else if (users[*rank].num_of_current_projects==20)
			{
				printf("You have 20 projects and you can not create another project.\n");
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
			find_user = finduserID(&userID, signuprank, users, username);
			if (find_user == true && strcmp(username, " ") != 0 && strcmp(project, " ") != 0 && strcmp(project, "") != 0 && strcmp(username, "") != 0) {
				if (find_in_user_projects(users, project, userID) == false && find_in_user_projects(users, project, *rank) == true && strcmp((users[*rank]).username, username) != 0) {
					add_user(project, users, userID, projects, *project_r);
					printf("New contributer \"%s\" is added to project \"%s\" now!\n", username, project);
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
			if (strcmp(username, " ") != 0 && strcmp(project, " ") != 0 && strcmp(project, "") != 0 && strcmp(username, "") != 0) {

				if (find_in_user_projects(users, project, *rank) == true && find_file_in_files(projects[projectID], username) == false) {
					add_file(&(projects[projectID]), username, &(users[*rank]),*rank,projectID);
					printf("New file \"%s\" is added to project \"%s\" now!\n", username, project);
				}
				else if (find_in_user_projects(users, project, *rank) == false) {
					printf("You can not use \"add_file\".I can not find this project in your projects!\n");
					return;
				}
				else if (strcmp(username, " ") == 0 || strcmp(project, " ") == 0 || strcmp(project, "") == 0 || strcmp(username, "") == 0) {
					printf("your instruction is not correct!\nadd_file <filename> <project's name>\n");
					return;
				}
				else
				{
					printf("I find \"%s\" file in \"%s\" project!\n", username, project);
					return;
				}
			}
			else
			{
				printf("your instruction is not correct!\nadd_file <filename> <project's name>\n");
				return;
			}
		}
		else
		{
			printf("Your instruction is not correct!\nadd_file <filename> <project's name>\n");
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
	User* u;
	Project* s;
	if ((users = (User*)malloc(sizeof(User) * 10)) == NULL) {
		printf("Error : Allocation memory for usernames has been failed!\n");
		free(users);
	}
	if ((projects = (Project*)malloc(sizeof(Project) * 10)) == NULL) {
		printf("Error : Allocation memory for usernames has been failed!\n");
		free(projects);
	}
	load_users_information(&users, &signuprank);
	load_projects_information(&projects, users, &project_r, signuprank);
	
	
	/*This part is main part and all of actions is here.In this part i use functions to get input and to check input .
	in addition i use MemoryAllocation functions to allocate memory when user want to have more memory size.*/

	while (true)
	{
		input = getinputasSTRING();
		checkinstructions(users, input, &state, &signuprank, &rank, &project_r, projects);
		save_users_information(users, signuprank);
		save_projects_information(projects, project_r,users);
		if (signuprank % 7 == 0 && signuprank != 0) {
			int size = signuprank;
			size += 10;
			u = (User*)realloc(users, sizeof(User) *size);
			if (u != NULL) {
				users = u;
			}
		}
		if (project_r % 7 == 0 && project_r != 0) {
			int size = project_r;
			size += 10;
			 s = (Project*)realloc(projects, sizeof(Project) *size);
			if (s != NULL) {
				projects = s;
			}
		}
	}


	return 0;
}