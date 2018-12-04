

/*function to redirect based off of token_list*/

void redirect(char **token_list, int stage){
	char *token;
	int less_than = 0;
	int more_than = 0;
	int status;

	char *first;	

	token = strtok(token_list[stage], " ");
	first = token;
	
	while (token != NULL) {
		
		if strcmp(token, '<') {
			less_than = 1;
			close(0);
			
		}
		
		else if (strcmp(token, '>')) {
			more_than = 1;
			close(1);
		}
	
		else if (less_than == 1) {	
			open(token, "r");
		}

		else if (more_than == 1) {
			open(token, "w");
		}
	
		token = strtok(NULL, " ");
	}
	pid_t pid = fork();

	if(pid == 0)	{	
		execl(*first, *first, NULL);			/*potentially change the arguments */
	}

	else {
		waitpid(pid, &status, 0);

      if ( WIFEXITED(status)) {
        int exit_status = WEXITSTATUS(status);

         if(exit_status){
            perror("redirrect child process returned with error\n");
				exit(1);
         }
      }
	}
}
	

	
	
	
	
	
	
	
