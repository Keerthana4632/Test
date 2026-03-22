pipeline {
    agent any

    environment {
        EXE_NAME = "calculator_app.exe"
        ARTIFACT_DIR = "artifacts"
        PUSH_BRANCH = "main"
    }

    triggers {
        pollSCM('H/2 * * * *')
    }

    stages {
        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure') {
            steps {
                sh '''
                    rm -rf build
                    mkdir -p build
                    cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=mingw-toolchain.cmake
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
                    cmake --build build
                '''
            }
        }

        stage('Store exe in repo') {
            steps {
                sh '''
                    mkdir -p ${ARTIFACT_DIR}

                    if [ -f build/${EXE_NAME} ]; then
                        cp build/${EXE_NAME} ${ARTIFACT_DIR}/${EXE_NAME}
                    else
                        echo "EXE not found"
                        find build -type f
                        exit 1
                    fi
                '''
            }
        }

        stage('Commit and Push') {
            steps {
                withCredentials([usernamePassword(
                    credentialsId: 'git-creds',
                    usernameVariable: 'GIT_USERNAME',
                    passwordVariable: 'GIT_PASSWORD'
                )]) {
                    sh '''
                        git config user.name "jenkins"
                        git config user.email "jenkins@local"

                        git add ${ARTIFACT_DIR}/${EXE_NAME}

                        if git diff --cached --quiet; then
                            echo "No changes to commit"
                            exit 0
                        fi

                        git commit -m "Auto-build: update ${EXE_NAME}"

                        git remote set-url origin https://${GIT_USERNAME}:${GIT_PASSWORD}@github.com/Keerthana4632/Test.git
                        git push origin HEAD:${PUSH_BRANCH}
                    '''
                }
            }
        }
    }

    post {
        success {
            archiveArtifacts artifacts: 'artifacts/*.exe', fingerprint: true
        }
    }
}
